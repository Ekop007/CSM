#include "mybrouser.h"
#include "ui_mybrouser.h"

MyBrouser::MyBrouser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyBrouser)
{
    ui->setupUi(this);
    this->setWindowTitle("Встроенный браузер");
}

MyBrouser::~MyBrouser()
{
    delete ui;
}

void MyBrouser::on_search_clicked()
{
    url.setUrl(ui->adres->text());
    ui->webView->setUrl(url);
}

void MyBrouser::on_next_clicked()
{
    ui->webView->forward();
}

void MyBrouser::on_prev_clicked()
{
    ui->webView->back();
}

void MyBrouser::on_stop_clicked()
{
    ui->webView->stop();
}

void MyBrouser::on_exit_clicked()
{
    this->hide();
    emit showMainWindow();
}
