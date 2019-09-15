#include "schemedialog.h"
#include "ui_schemedialog.h"

SchemeDialog::SchemeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SchemeDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("Размерность схемы"));
}

SchemeDialog::~SchemeDialog()
{
    delete ui;
}

void SchemeDialog::setPtr(std::shared_ptr<SchemeParams> &ptr)
{
    s_par_ptr = ptr;
}

void SchemeDialog::on_OK_clicked()
{
    s_par_ptr->node_count = static_cast<size_t>(ui->node_count->value());
    s_par_ptr->resistors = static_cast<size_t>(ui->resistors->value());
    s_par_ptr->capasitors = static_cast<size_t>(ui->capacitors->value());
    s_par_ptr->inductances = static_cast<size_t>(ui->inductances->value());
    s_par_ptr->itun = static_cast<size_t>(ui->itun->value());
    s_par_ptr->inun = static_cast<size_t>(ui->inun->value());
    s_par_ptr->itut = static_cast<size_t>(ui->itut->value());
    s_par_ptr->inut = static_cast<size_t>(ui->inut->value());
    s_par_ptr->b_p_transistors = static_cast<size_t>(ui->bp_transistors->value());
    s_par_ptr->u_p_transistors = static_cast<size_t>(ui->up_transistors->value());
    s_par_ptr->oper_ampfilers = static_cast<size_t>(ui->amplifiers->value());
    s_par_ptr->transformers = static_cast<size_t>(ui->transformers->value());
    s_par_ptr->p_o_ampfilers = static_cast<size_t>(ui->p_o_alplifiers->value());
    s_par_ptr->perf_transistors = static_cast<size_t>(ui->perf_tranformers->value());
    this->hide();
    emit showMainWindow();
}
