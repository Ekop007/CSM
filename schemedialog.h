#ifndef SCHEMEDIALOG_H
#define SCHEMEDIALOG_H

#include <QDialog>
#include <memory>
#include "schemeparams.h"

namespace Ui {
class SchemeDialog;
}

class SchemeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SchemeDialog(QWidget *parent = nullptr);
    ~SchemeDialog();
    void getPtr(std::shared_ptr<SchemeParams> &ptr);

signals:
    void showMainWindow();

private slots:
    void on_OK_clicked();

private:
    Ui::SchemeDialog *ui;
    std::shared_ptr<SchemeParams> s_par;
};

#endif // SCHEMEDIALOG_H
