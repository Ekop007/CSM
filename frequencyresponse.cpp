#include "frequencyresponse.h"
#include "ui_frequencyresponse.h"

FrequencyResponse::FrequencyResponse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrequencyResponse), f(3)
{
    ui->setupUi(this);
    this->setWindowTitle("Вид частотной характеристики");
}

FrequencyResponse::~FrequencyResponse()
{
    delete ui;
}

void FrequencyResponse::setPtr(std::shared_ptr<CalculationParams> &ptr)
{
    calculation_params_ptr = ptr;
}

void FrequencyResponse::on_Ok_clicked()
{
    switch(f)
    {
        case 0:
        calculation_params_ptr->flag_frequency_response = f;
        calculation_params_ptr->frequency[0] = ui->value1->value();
        this->hide();
        emit showMainWindow();
        break;

        case 1:
        calculation_params_ptr->flag_frequency_response = f;
        calculation_params_ptr->frequency[0] = ui->value1->value();
        calculation_params_ptr->frequency[1] = ui->value2->value();
        calculation_params_ptr->frequency[2] = ui->value3->value();
        this->hide();
        emit showMainWindow();
        break;

        case 2:
        calculation_params_ptr->flag_frequency_response = f;
        calculation_params_ptr->frequency[0] = ui->value1->value();
        calculation_params_ptr->frequency[1] = ui->value2->value();
        calculation_params_ptr->frequency[2] = ui->value3->value();
        this->hide();
        emit showMainWindow();
        break;

        default:
        error_mes.showMessage("Не выбран вид частотной характеристики!");
        error_mes.exec();
        break;
    }
}

void FrequencyResponse::on_B1_clicked()
{
    f = 0;
    ui->line1->setText("Значение частоты (кГц)");
    ui->line2->setText("");
    ui->line3->setText("");
    ui->value1->setEnabled(true);
    ui->value2->setEnabled(false);
    ui->value3->setEnabled(false);
}

void FrequencyResponse::on_B2_clicked()
{
    f = 1;
    ui->line1->setText("Минимальная частота Fmin(кГц)");
    ui->line2->setText("Максимальная частота Fmax(кГц)");
    ui->line3->setText("Шаг изменения частоты dF(кГц)");
    ui->value1->setEnabled(true);
    ui->value2->setEnabled(true);
    ui->value3->setEnabled(true);
}

void FrequencyResponse::on_B3_clicked()
{
    f = 2;
    ui->line1->setText("Минимальная частота Fmin(кГц)");
    ui->line2->setText("Максимальная частота Fmax(кГц)");
    ui->line3->setText("Отношение соседних частот K");
    ui->value1->setEnabled(true);
    ui->value2->setEnabled(true);
    ui->value3->setEnabled(true);
}
