#ifndef INPUTELEMENTS_H
#define INPUTELEMENTS_H

#include <QDialog>
#include <sstream>
#include <memory>
#include "elementsparams.h"

namespace Ui
{
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
    void setMaxId(std::size_t mi);
    void init();

signals:
    void showMainWindow();

private:

    void check();
    // dialog title
    void resetValue();
    void resetSize();
    void resistorTittle();
    void caparisonTitle();
    void inductancesTitle();
    void ITUNTitle();
    void INUNTitle();
    void ITUTTitle();
    void INUTTitle();
    void BPTransistorTitle();
    void UPTransistorTitle();
    void OperAmplifierTitle();
    void TransformerTitle();
    void POAmplifierTitle();
    void PerfTransistorTitle();
    void PerfectTransformerTitle();

    // read parameters
    void resistorPar();
    void caparisonPar();
    void inductancesPar();
    void ITUNPar();
    void INUNPar();
    void ITUTPar();
    void INUTPar();
    void BPTransistorPar();
    void UPTransistorPar();
    void OperAmplifierPar();
    void TransformerPar();
    void POAmplifierPar();
    void PerfTransistorPar();
    void PerfectTransformerPar();

private slots:
    void on_next_element_clicked();

public:
    std::array<std::size_t, Cosnst_Values::array_size> elem;

private:   
    Ui::InputElements *ui;
    size_t element_number;
    size_t element_id;
    size_t max_id;
    size_t max_number;
    const int width1;
    const int width2;
    int f;
    std::stringstream str;
    std::array<Func_Pointer, Cosnst_Values::array_size> titles;
    std::array<Func_Pointer, Cosnst_Values::array_size> read_par;
    std::shared_ptr<ElementsParams> elements_params_ptr;
};

#endif // INPUTELEMENTS_H
