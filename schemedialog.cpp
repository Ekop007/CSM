#include "schemedialog.h"
#include "ui_schemedialog.h"

SchemeDialog::SchemeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SchemeDialog)
{
    ui->setupUi(this);
}

SchemeDialog::~SchemeDialog()
{
    delete ui;
}

void SchemeDialog::getPtr(std::shared_ptr<SchemeParams> &ptr)
{
    s_par = ptr;
}

void SchemeDialog::on_OK_clicked()
{
    SchemeParams p(ui->node_count->value(), ui->resistors->value(), ui->capacitors->value(), ui->inductances->value(),
                   ui->itun->value(), ui->inun->value(), ui->itut->value(), ui->inut->value(),
                   ui->bp_transistors->value(), ui->up_transistors->value(), ui->amplifiers->value(),
                   ui->p_o_alplifiers->value(), ui->transformers->value(), ui->perf_tranformers->value());
    SchemeParams *t = s_par.get();
    (*t) = std::move(p);
    this->hide();
    emit showMainWindow();
}
