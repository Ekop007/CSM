#ifndef INPUTELEMENTS_H
#define INPUTELEMENTS_H

#include <QDialog>
#include <sstream>
#include <array>
#include <memory>
#include "elementsparams.h"

namespace Ui {
class InputElements;
}

class InputElements : public QDialog
{
    Q_OBJECT
    using Func_Pointer = void (InputElements::*)();

public:
    explicit InputElements(QWidget *parent = nullptr);
    ~InputElements();

    void setPtr(std::shared_ptr<ElementsParams> &ptr);

signals:
    void showMainWindow();

private:
    void resetValue();
    void resistorTittle();
    void caparisonTitle();
    void inductancesTitle();
    void resistorPar();
    void caparisonPar();
    void inductancesPar();

private slots:
    void on_next_element_clicked();

private:
    Ui::InputElements *ui;
    size_t element_number;
    size_t element_id;
    size_t max_id;
    size_t max_number;
    std::stringstream str;
    std::array<Func_Pointer, 12> titles;
    std::array<Func_Pointer, 12> read_par;
    std::shared_ptr<ElementsParams> e_par_ptr;
};

#endif // INPUTELEMENTS_H
