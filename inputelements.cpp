#include "inputelements.h"
#include "ui_inputelements.h"

InputElements::InputElements(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputElements),
    element_number(0), element_id(0), max_id(3), max_number(1)
{
    ui->setupUi(this);
    ui->param_1->hide();
    ui->p1_value->hide();

    titles[0] = &InputElements::resistorTittle;
    titles[1] = &InputElements::caparisonTitle;
    titles[2] = &InputElements::inductancesTitle;

    read_par[0] = &InputElements::resistorPar;
    read_par[1] = &InputElements::caparisonPar;
    read_par[2] = &InputElements::inductancesPar;

    this->move(300, 200);
    resetValue();
    // Изменение имени окна и наименования элемента цепи
    (this->*titles[element_id])();
}

InputElements::~InputElements()
{
    delete ui;
}

void InputElements::setPtr(std::shared_ptr<ElementsParams> &ptr)
{
    e_par_ptr = ptr;
}

void InputElements::resetValue()
{
    str << (element_number + 1);
    ui->node_nm->setValue(0);
    ui->node_np->setValue(0);
    ui->p1_value->setValue(0);
    ui->ph_q_value->setValue(0);
    ui->element_number->setText(QString(str.str().c_str()));
    str.str("");
}

void InputElements::resistorTittle()
{
    this->setWindowTitle(QString("R"));
    ui->name_element->setText(QString("R"));
}

void InputElements::caparisonTitle()
{
    this->setWindowTitle(QString("C"));
    ui->name_element->setText(QString("C"));
}

void InputElements::inductancesTitle()
{
    this->setWindowTitle(QString("L"));
    ui->name_element->setText(QString("L"));
}

void InputElements::resistorPar()
{
    e_par_ptr->z_r[element_number] = ui->ph_q_value->value();
    e_par_ptr->in_r[element_number].first = ui->node_nm->value();
    e_par_ptr->in_r[element_number].second = ui->node_np->value();
}

void InputElements::caparisonPar()
{
    e_par_ptr->z_c[element_number] = ui->ph_q_value->value();
    e_par_ptr->in_c[element_number].first = ui->node_nm->value();
    e_par_ptr->in_c[element_number].second = ui->node_np->value();
}

void InputElements::inductancesPar()
{
    e_par_ptr->z_l[element_number] = ui->ph_q_value->value();
    e_par_ptr->in_l[element_number].first = ui->node_nm->value();
    e_par_ptr->in_l[element_number].second = ui->node_np->value();
}


void InputElements::on_next_element_clicked()
{
    this->hide();
    /* Здесь считывается информация  в вектор */
    (this->*read_par[element_id])();
    resetValue();
    if (element_id + 1 == max_id)
    {
        element_id = 0;
        element_number = 0;
        emit showMainWindow();
    }
    else
    {
        if (element_number + 1 < max_number)
        {
            ++element_number;
        }
        else
        {
            element_number = 0;
            ++element_id;
            // Изменение имени окна и наименования элемента цепи
            (this->*titles[element_id])();
        }
        this->show();
    }
}
