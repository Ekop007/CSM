#include <sstream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scheme(new SchemeDialog()),
    elements(new InputElements())
{
    ui->setupUi(this);
    scheme->hide();
    elements->hide();
    s_par_ptr = std::make_shared<SchemeParams>();
    e_par_ptr = std::make_shared<ElementsParams>();
    scheme->setPtr(s_par_ptr);
    elements->setPtr(e_par_ptr);
    connect(scheme.get(), SIGNAL(showMainWindow()), this, SLOT(showThis()));
    connect(elements.get(), SIGNAL(showMainWindow()), this, SLOT(showThis()));
    showParams();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showParams()
{
    std::stringstream str;
    str << "Node count: " << s_par_ptr->node_count << std::endl;
    str << "Resisters: " << s_par_ptr->resistors << std::endl;
    str << "Capasitor: " << s_par_ptr->capasitors << std::endl;
    str << "Inductions: " << s_par_ptr->inductances << std::endl;
    str << "ITUN: " << s_par_ptr->itun << std::endl;
    str << "INUN: " << s_par_ptr->inun << std::endl;
    str << "ITUT: " << s_par_ptr->itut << std::endl;
    QString log(str.str().c_str());
    ui->Logger->setText(log);
}


void MainWindow::showThis()
{
    this->show();
    showParams();
    e_par_ptr->Init(s_par_ptr->resistors, s_par_ptr->capasitors, s_par_ptr->inductances);
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

void MainWindow::on_ID_CONS_triggered()
{
    this->hide();
    elements->show();
}
