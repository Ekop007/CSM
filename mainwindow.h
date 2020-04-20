#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "schemedialog.h"
#include "inputelements.h"
#include "editionelements.h"
#include "frequencyresponse.h"
#include "nodedialog.h"
#include "mybrouser.h"
#include "calculator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    void showParams();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showThis();
    void continueInput();

private slots:
    void on_ID_EXIT_triggered();

    void on_ID_RED_triggered();

    void on_ID_CONS_triggered();

    void on_ID_OFILE_triggered();

    void on_ID_IFILE_triggered();

    void on_ID_F_triggered();

    void on_ID_IO_triggered();

    void on_ID_SYS_triggered();

    void on_ID_PRIV_triggered();

    void on_ID_INTERNET_triggered();

    void on_ID_CALC_triggered();

    void on_ID_CALC_MATRIX_triggered();

private:
    void setValues();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<SchemeDialog> scheme;
    std::unique_ptr<InputElements> elements;
    std::unique_ptr<EditionElements> edition;
    std::unique_ptr<FrequencyResponse> frequency;
    std::unique_ptr<NodeDialog> ionodes;
    std::unique_ptr<MyBrouser> brouser;
    std::shared_ptr<SchemeParams> scheme_params_ptr;
    std::shared_ptr<ElementsParams> elements_params_ptr;
    std::shared_ptr<CalculationParams> calculation_params_ptr;
    std::unique_ptr<Calculator> calculator;
    bool systemBrouser;
};

#endif // MAINWINDOW_H
