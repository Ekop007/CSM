#ifndef SCHEMEDIALOG_H
#define SCHEMEDIALOG_H

#include <QDialog>

namespace Ui {
class SchemeDialog;
}

class SchemeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SchemeDialog(QWidget *parent = nullptr);
    ~SchemeDialog();

private slots:
    void on_OK_clicked();

private:
    Ui::SchemeDialog *ui;
};

#endif // SCHEMEDIALOG_H
