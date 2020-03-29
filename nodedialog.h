#ifndef NODEDIALOG_H
#define NODEDIALOG_H

#include <QDialog>
#include <memory>
#include "calculationparams.h"

namespace Ui {
class NodeDialog;
}

class NodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NodeDialog(QWidget *parent = nullptr);
    ~NodeDialog();

    void setPtr(std::shared_ptr<CalculationParams> &ptr);
    void setMaxNode(int max);

signals:
    void showMainWindow();


private slots:
    void on_pushButton_clicked();

private:
    Ui::NodeDialog *ui;
    std::shared_ptr<CalculationParams> calculation_params_ptr;

};

#endif // NODEDIALOG_H
