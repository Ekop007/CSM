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
    s_par_ptr->node_count = ui->node_count->value();
    s_par_ptr->resistors = ui->resistors->value();
    s_par_ptr->capasitors = ui->capacitors->value();
    s_par_ptr->inductances = ui->inductances->value();
    s_par_ptr->itun = ui->itun->value();
    s_par_ptr->inun = ui->inun->value();
    s_par_ptr->itut = ui->itut->value();
    s_par_ptr->inut = ui->inut->value();
    s_par_ptr->b_p_transistors = ui->bp_transistors->value();
    s_par_ptr->u_p_transistors = ui->up_transistors->value();
    s_par_ptr->oper_ampfilers = ui->amplifiers->value();
    s_par_ptr->transformers = ui->transformers->value();
    s_par_ptr->p_o_ampfilers = ui->p_o_alplifiers->value();
    s_par_ptr->perf_transistors = ui->perf_tranformers->value();
    this->hide();
    emit showMainWindow();
}
