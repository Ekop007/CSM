#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "schemedialog.h"

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

private:
    Ui::MainWindow *ui;
    SchemeDialog *scheme;
    std::shared_ptr<SchemeParams> s_par;
};

#endif // MAINWINDOW_H
