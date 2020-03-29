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
    scheme_params_ptr = ptr;
}

void SchemeDialog::on_OK_clicked()
{
    scheme_params_ptr->node_count = static_cast<size_t>(ui->node_count->value());
    scheme_params_ptr->resistors = static_cast<size_t>(ui->resistors->value());
    scheme_params_ptr->capasitors = static_cast<size_t>(ui->capacitors->value());
    scheme_params_ptr->inductances = static_cast<size_t>(ui->inductances->value());
    scheme_params_ptr->itun = static_cast<size_t>(ui->itun->value());
    scheme_params_ptr->inun = static_cast<size_t>(ui->inun->value());
    scheme_params_ptr->itut = static_cast<size_t>(ui->itut->value());
    scheme_params_ptr->inut = static_cast<size_t>(ui->inut->value());
    scheme_params_ptr->b_p_transistors = static_cast<size_t>(ui->bp_transistors->value());
    scheme_params_ptr->u_p_transistors = static_cast<size_t>(ui->up_transistors->value());
    scheme_params_ptr->oper_amplifiers = static_cast<size_t>(ui->amplifiers->value());
    scheme_params_ptr->transformers = static_cast<size_t>(ui->transformers->value());
    scheme_params_ptr->p_o_amplifiers = static_cast<size_t>(ui->p_o_alplifiers->value());
    scheme_params_ptr->perf_transistors = static_cast<size_t>(ui->perf_tranformers->value());
    this->hide();
    emit nextInputWindow();
}
