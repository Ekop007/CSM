#include <sstream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scheme(new SchemeDialog())
{
    ui->setupUi(this);
    s_par = std::make_shared<SchemeParams>();
    scheme->getPtr(s_par);
    scheme->hide();
    connect(scheme, SIGNAL(showMainWindow()), this, SLOT(showThis()));
    showParams();
}

MainWindow::~MainWindow()
{
    delete scheme;
    delete ui;
}

void MainWindow::showParams()
{
    std::stringstream str;
    str << "Node count: " << s_par->node_count << std::endl;
    str << "Resisters: " << s_par->resistors << std::endl;
    str << "Capasitor: " << s_par->capasitors << std::endl;
    str << "Inductions: " << s_par->inductions << std::endl;
    str << "ITUN: " << s_par->itun << std::endl;
    str << "INUN: " << s_par->inun << std::endl;
    str << "ITUT: " << s_par->itut << std::endl;
    QString log(str.str().c_str());
    ui->Logger->setText(log);
}


void MainWindow::showThis()
{
    this->show();
    showParams();
}

void MainWindow::on_ID_EXIT_triggered()
{
    QApplication::quit();
}

void MainWindow::on_ID_RED_triggered()
{
    this->hide();
    scheme->show();
}
