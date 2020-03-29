#ifndef FREQUENCYRESPONSE_H
#define FREQUENCYRESPONSE_H

#include <memory>
#include <QDialog>
#include <QErrorMessage>
#include "calculationparams.h"

namespace Ui {
class FrequencyResponse;
}

class FrequencyResponse : public QDialog
{
    Q_OBJECT

public:
    explicit FrequencyResponse(QWidget *parent = nullptr);
    ~FrequencyResponse();
    void setPtr(std::shared_ptr<CalculationParams> &ptr);

signals:
    void showMainWindow();

private slots:
    void on_Ok_clicked();

    void on_B1_clicked();

    void on_B2_clicked();

    void on_B3_clicked();

private:
    Ui::FrequencyResponse *ui;
    int f;
    QErrorMessage error_mes;
    std::shared_ptr<CalculationParams> calculation_params_ptr;
};

#endif // FREQUENCYRESPONSE_H
