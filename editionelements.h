#ifndef EDITIONELEMENTS_H
#define EDITIONELEMENTS_H

#include <memory>
#include <QDialog>
#include <QListWidget>
#include "elementsparams.h"

namespace Ui {
class EditionElements;
}

class EditionElements : public QDialog
{
    Q_OBJECT
    using Func_Pointer = void (EditionElements::*)();

public:
    explicit EditionElements(QWidget *parent = nullptr);
    ~EditionElements();

    void initPointer(std::shared_ptr<ElementsParams> &shptr);
    void initPar();
    void initListPar();

signals:
    void showMainWindow();

private:

 //   void check();
    // dialog title
    void resetValue();

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

    // read parameters
    void readResistorPar();
    void readCaparisonPar();
    void readInductancesPar();
    void readITUNPar();
    void readINUNPar();
    void readITUTPar();
    void readINUTPar();
    void readBPTransistorPar();
    void readUPTransistorPar();
    void readOperAmplifierPar();
    void readTransformerPar();
    void readPOAmplifierPar();
    void readPerfTransistorPar();

    // save parameters
    void saveResistorPar();
    void saveCaparisonPar();
    void saveInductancesPar();
    void saveITUNPar();
    void saveINUNPar();
    void saveITUTPar();
    void saveINUTPar();
    void saveBPTransistorPar();
    void saveUPTransistorPar();
    void saveOperAmplifierPar();
    void saveTransformerPar();
    void savePOAmplifierPar();
    void savePerfTransistorPar();


private slots:
    void on_component_list_itemClicked(QListWidgetItem *item);

    void on_exit_clicked();

    void on_change_clicked();

    void on_elenent_number_valueChanged(int arg1);

private:
    Ui::EditionElements *ui;
    size_t element_number;
    size_t element_id;
    size_t max_id;
    int f;
    std::array<Func_Pointer, Cosnst_Values::array_size> titles;
    std::array<Func_Pointer, Cosnst_Values::array_size> read_par;
    std::array<Func_Pointer, Cosnst_Values::array_size> save_par;
    std::shared_ptr<ElementsParams> elements_params_ptr;
};

#endif // EDITIONELEMENTS_H
