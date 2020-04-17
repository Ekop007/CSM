#include "nodedialog.h"
#include "ui_nodedialog.h"

NodeDialog::NodeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NodeDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Входные и выходные узлы");
}

NodeDialog::~NodeDialog()
{
    delete ui;
}

void NodeDialog::setPtr(std::shared_ptr<CalculationParams> &ptr)
{
    calculation_params_ptr = ptr;
}

void NodeDialog::setMaxNode(int max)
{
    ui->node_km->setMaximum(max);
    ui->node_kp->setMaximum(max);
    ui->node_nm->setMaximum(max);
    ui->node_np->setMaximum(max);
}

void NodeDialog::on_pushButton_clicked()
{
    calculation_params_ptr->in_nodes[0] = ui->node_np->value();
    calculation_params_ptr->in_nodes[1] = ui->node_nm->value();
    calculation_params_ptr->out_nodes[0] = ui->node_kp->value();
    calculation_params_ptr->out_nodes[1] = ui->node_km->value();
    this->hide();
    emit showMainWindow();
}
