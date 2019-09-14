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

void SchemeDialog::on_OK_clicked()
{

}
