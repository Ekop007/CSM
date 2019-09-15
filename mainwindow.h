#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "schemedialog.h"
#include "inputelements.h"

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

private slots:
    void on_ID_EXIT_triggered();

    void on_ID_RED_triggered();

    void on_ID_CONS_triggered();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<SchemeDialog> scheme;
    std::unique_ptr<InputElements> elements;
    std::shared_ptr<SchemeParams> s_par_ptr;
    std::shared_ptr<ElementsParams> e_par_ptr;
};

#endif // MAINWINDOW_H
