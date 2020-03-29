#include <sstream>
#include <QFileDialog>
#include <fstream>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scheme(new SchemeDialog()),
    elements(new InputElements()),
    edition(new EditionElements()),
    frequency(new FrequencyResponse()),
    ionodes(new NodeDialog),
    brouser(new MyBrouser),
    calculator(new Calculator)
{
    ui->setupUi(this);
    scheme->hide();
    elements->hide();
    edition->hide();
    frequency->hide();
    ionodes->hide();
    brouser->hide();
    systemBrouser = false;
    scheme_params_ptr = std::make_shared<SchemeParams>();
    elements_params_ptr = std::make_shared<ElementsParams>();
    calculation_params_ptr = std::make_shared<CalculationParams>();
    scheme->setPtr(scheme_params_ptr);
    elements->setPtr(elements_params_ptr);
    edition->initPointer(elements_params_ptr);
    frequency->setPtr(calculation_params_ptr);
    ionodes->setPtr(calculation_params_ptr);
    calculator->setSchemeParams(scheme_params_ptr);
    calculator->setElemetsParams(elements_params_ptr);
    calculator->setCalculationParams(calculation_params_ptr);
    connect(scheme.get(), SIGNAL(nextInputWindow()), this, SLOT(continueInput()));
    connect(elements.get(), SIGNAL(showMainWindow()), this, SLOT(showThis()));
    connect(edition.get(), SIGNAL(showMainWindow()), this, SLOT(showThis()));
    connect(frequency.get(), SIGNAL(showMainWindow()), this, SLOT(showThis()));
    connect(ionodes.get(), SIGNAL(showMainWindow()), this, SLOT(showThis()));
    connect(brouser.get(), SIGNAL(showMainWindow()), this, SLOT(showThis()));
    showParams();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showParams()
{
    std::stringstream str;
    str << "Node count: " << scheme_params_ptr->node_count << std::endl;
    str << "Resisters: " << scheme_params_ptr->resistors << std::endl;
    str << "Capasitor: " << scheme_params_ptr->capasitors << std::endl;
    str << "Inductions: " << scheme_params_ptr->inductances << std::endl;
    str << "ITUN: " << scheme_params_ptr->itun << std::endl;
    str << "INUN: " << scheme_params_ptr->inun << std::endl;
    str << "ITUT: " << scheme_params_ptr->itut << std::endl;
    QString log(str.str().c_str());
    ui->Logger->setText(log);
}


void MainWindow::showThis()
{
    this->show();
    showParams();
}

void MainWindow::continueInput()
{
    elements_params_ptr->Init(scheme_params_ptr->resistors, scheme_params_ptr->capasitors, scheme_params_ptr->inductances, scheme_params_ptr->itun, scheme_params_ptr->inun, scheme_params_ptr->itut,
                    scheme_params_ptr->inut, scheme_params_ptr->b_p_transistors, scheme_params_ptr->u_p_transistors, scheme_params_ptr->oper_amplifiers, scheme_params_ptr->transformers,
                    scheme_params_ptr->p_o_amplifiers, scheme_params_ptr->perf_transistors);
    setValues();
    elements->init();
    elements->show();
}

void MainWindow::on_ID_EXIT_triggered()
{
    QApplication::quit();
}

void MainWindow::on_ID_RED_triggered()
{
    this->hide();
    edition->initListPar();
    edition->show();
}

void MainWindow::on_ID_CONS_triggered()
{
    this->hide();
    //setValues();
    //elements->init();
    scheme->show();
}

void MainWindow::setValues()
{
    elements->elem[0] =  scheme_params_ptr->resistors;
    elements->elem[1] =  scheme_params_ptr->capasitors;
    elements->elem[2] =  scheme_params_ptr->inductances;
    elements->elem[3] =  scheme_params_ptr->itun;
    elements->elem[4] =  scheme_params_ptr->inun;
    elements->elem[5] =  scheme_params_ptr->itut;
    elements->elem[6] =  scheme_params_ptr->inut;
    elements->elem[7] =  scheme_params_ptr->b_p_transistors;
    elements->elem[8] =  scheme_params_ptr->u_p_transistors;
    elements->elem[9] =  scheme_params_ptr->oper_amplifiers;
    elements->elem[10] = scheme_params_ptr->transformers;
    elements->elem[11] = scheme_params_ptr->p_o_amplifiers;
    elements->elem[12] = scheme_params_ptr->perf_transistors;
    elements_params_ptr->maxnodes = scheme_params_ptr->node_count;
}

void MainWindow::on_ID_OFILE_triggered()
{
    QString file = QFileDialog::getSaveFileName(this, "Сохранить в файл");
    std::ofstream out(file.toStdString());
    if (out.is_open())
    {
        scheme_params_ptr->write(out);
        elements_params_ptr->writeR(out);
        elements_params_ptr->writeC(out);
        elements_params_ptr->writeL(out);
        elements_params_ptr->writeITUN(out);
        elements_params_ptr->writeINUN(out);
        elements_params_ptr->writeITUT(out);
        elements_params_ptr->writeINUT(out);
        elements_params_ptr->writeBPTrans(out);
        elements_params_ptr->writeUPTrans(out);
        elements_params_ptr->writeOperAmp(out);
        elements_params_ptr->writeTransformer(out);
        elements_params_ptr->writePOAmp(out);
//        elements_params_ptr->writePerfTrans(out);
        calculation_params_ptr->write(out);
        out.close();
    }

}

void MainWindow::on_ID_IFILE_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Открытие файла");
    std::ifstream in(file.toStdString());
    if (in.is_open())
    {
        scheme_params_ptr->read(in);
        elements_params_ptr->readR(in);
        elements_params_ptr->readC(in);
        elements_params_ptr->readL(in);
        elements_params_ptr->readITUN(in);
        elements_params_ptr->readINUN(in);
        elements_params_ptr->readITUT(in);
        elements_params_ptr->readINUT(in);
        elements_params_ptr->readBPTrans(in);
        elements_params_ptr->readUPTrans(in);
        elements_params_ptr->readOperAmp(in);
        elements_params_ptr->readTransformer(in);
        elements_params_ptr->readPOAmp(in);
//        elements_params_ptr->readPerfTrans(in);
        calculation_params_ptr->read(in);
        in.close();
        showParams();
    }
}

void MainWindow::on_ID_F_triggered()
{
    this->hide();
    frequency->show();
}

void MainWindow::on_ID_IO_triggered()
{
    this->hide();
    ionodes->setMaxNode(static_cast<int>(scheme_params_ptr->node_count));
    ionodes->show();
}

void MainWindow::on_ID_SYS_triggered()
{
    systemBrouser = true;
}

void MainWindow::on_ID_PRIV_triggered()
{
    systemBrouser = false;
}

void MainWindow::on_ID_INTERNET_triggered()
{
    if (systemBrouser)
    {
        //system("firefox 192.168.43.118");
        system("firefox ~/MF");
    }
    else
    {
        this->hide();
        brouser->show();
    }
}

void MainWindow::on_ID_CALC_triggered()
{
    calculator->setSizeW();
    calculator->form_D();
    ui->Logger->clear();
    auto W = calculator->getW();
    std::stringstream str;
    for (size_t i = 0; i < W.getR(); ++i)
    {
        for (size_t j = 0; j < W.getC(); ++j)
        {
            str << W[i][j] << " ";
        }
        str << std::endl;
    }
    ui->Logger->setText(QString(str.str().c_str()));
}
