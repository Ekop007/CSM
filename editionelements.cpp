#include "editionelements.h"
#include "ui_editionelements.h"


EditionElements::EditionElements(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditionElements), element_number(13), element_id(13), max_id(12), f(0)
{
    ui->setupUi(this);
    titles[0] = &EditionElements::resistorTittle;
    titles[1] = &EditionElements::caparisonTitle;
    titles[2] = &EditionElements::inductancesTitle;
    titles[3] = &EditionElements::ITUNTitle;
    titles[4] = &EditionElements::INUNTitle;
    titles[5] = &EditionElements::ITUTTitle;
    titles[6] = &EditionElements::INUTTitle;
    titles[7] = &EditionElements::BPTransistorTitle;
    titles[8] = &EditionElements::UPTransistorTitle;
    titles[9] = &EditionElements::OperAmplifierTitle;
    titles[10] = &EditionElements::TransformerTitle;
    titles[11] = &EditionElements::POAmplifierTitle;
    titles[12] = &EditionElements::PerfTransistorTitle;

    read_par[0] = &EditionElements::readResistorPar;
    read_par[1] = &EditionElements::readCaparisonPar;
    read_par[2] = &EditionElements::readInductancesPar;
    read_par[3] = &EditionElements::readITUNPar;
    read_par[4] = &EditionElements::readINUNPar;
    read_par[5] = &EditionElements::readITUTPar;
    read_par[6] = &EditionElements::readINUTPar;
    read_par[7] = &EditionElements::readBPTransistorPar;
    read_par[8] = &EditionElements::readUPTransistorPar;
    read_par[9] = &EditionElements::readOperAmplifierPar;
    read_par[10] = &EditionElements::readTransformerPar;
    read_par[11] = &EditionElements::readPOAmplifierPar;
    read_par[12] = &EditionElements::readPerfTransistorPar;

    save_par[0] = &EditionElements::saveResistorPar;
    save_par[1] = &EditionElements::saveCaparisonPar;
    save_par[2] = &EditionElements::saveInductancesPar;
    save_par[3] = &EditionElements::saveITUNPar;
    save_par[4] = &EditionElements::saveINUNPar;
    save_par[5] = &EditionElements::saveITUTPar;
    save_par[6] = &EditionElements::saveINUTPar;
    save_par[7] = &EditionElements::saveBPTransistorPar;
    save_par[8] = &EditionElements::saveUPTransistorPar;
    save_par[9] = &EditionElements::saveOperAmplifierPar;
    save_par[10] = &EditionElements::saveTransformerPar;
    save_par[11] = &EditionElements::savePOAmplifierPar;
    save_par[12] = &EditionElements::savePerfTransistorPar;

}

EditionElements::~EditionElements()
{
    delete ui;
}

void EditionElements::initPar()
{
    switch (f)
    {
    case 0: // R L C
        ui->p1->hide();
        ui->p2->hide();
        ui->p3->hide();
        ui->p4->hide();
        ui->p5->hide();
        ui->p1_value->hide();
        ui->p2_value->hide();
        ui->p3_value->hide();
        ui->p4_value->hide();
        ui->p5_value->hide();
        ui->km_l->hide();
        ui->kp_l->hide();
        ui->node_km->hide();
        ui->node_km->hide();
        break;

    case 1: // I N/T
        ui->p0->show();
        ui->p0_value->show();
        ui->p1->show();
        ui->p2->show();
        ui->p3->show();
        ui->p4->hide();
        ui->p5->hide();
        ui->p1_value->show();
        ui->p2_value->show();
        ui->p3_value->show();
        ui->p4_value->hide();
        ui->p5_value->hide();
        ui->km_l->show();
        ui->kp_l->show();
        ui->node_km->show();
        ui->node_km->show();
        break;

    case 2: // BP trans
        ui->p0->show();
        ui->p0_value->show();
        ui->p1->show();
        ui->p2->show();
        ui->p3->show();
        ui->p4->show();
        ui->p5->show();
        ui->p1_value->show();
        ui->p2_value->show();
        ui->p3_value->show();
        ui->p4_value->show();
        ui->p5_value->show();
        ui->km_l->show();
        ui->kp_l->hide();
        ui->node_km->show();
        ui->node_kp->hide();
        break;
    case 3: // UP trans || Perf trans
        ui->p0->show();
        ui->p0_value->show();
        ui->p1->show();
        ui->p2->show();
        ui->p3->show();
        ui->p4->show();
        ui->p5->hide();
        ui->p1_value->show();
        ui->p2_value->show();
        ui->p3_value->show();
        ui->p4_value->show();
        ui->p5_value->hide();
        ui->km_l->show();
        ui->kp_l->hide();
        ui->node_km->show();
        ui->node_kp->hide();
        break;
    case 4: // transformer || amplifier
        ui->p0->show();
        ui->p0_value->show();
        ui->p1->show();
        ui->p2->show();
        ui->p3->show();
        ui->p4->hide();
        ui->p5->hide();
        ui->p1_value->show();
        ui->p2_value->show();
        ui->p3_value->show();
        ui->p4_value->hide();
        ui->p5_value->hide();
        ui->km_l->show();
        ui->kp_l->show();
        ui->node_km->show();
        ui->node_km->show();
        break;
    }
}

void EditionElements::initListPar()
{
    if (ui->component_list->count() > 0)
    {
        ui->component_list->clear();
    }
    if(elements_params_ptr->nodeR.getR() > 1)
    {
        ui->component_list->addItem(QString("R"));
    }
    if(elements_params_ptr->nodeC.getR() > 1)
    {
        ui->component_list->addItem(QString("C"));
    }
    if(elements_params_ptr->nodeL.getR() > 1)
    {
        ui->component_list->addItem(QString("L"));
    }
    if(elements_params_ptr->nodeITUN.getR() > 1)
    {
        ui->component_list->addItem(QString("ITUN"));
    }
    if(elements_params_ptr->nodeINUN.getR() > 1)
    {
        ui->component_list->addItem(QString("INUN"));
    }
    if(elements_params_ptr->nodeITUT.getR() > 1)
    {
        ui->component_list->addItem(QString("ITUT"));
    }
    if(elements_params_ptr->nodeINUT.getR() > 1)
    {
        ui->component_list->addItem(QString("INUT"));
    }
    if(elements_params_ptr->nodeBPTrans.getR() > 1)
    {
        ui->component_list->addItem(QString("BP Transistor"));
    }
    if(elements_params_ptr->nodeUPTrans.getR() > 1)
    {
        ui->component_list->addItem(QString("UP Transistor"));
    }
    if(elements_params_ptr->nodeOperAmp.getR() > 1)
    {
        ui->component_list->addItem(QString("Op Amplifier"));
    }
    if(elements_params_ptr->nodeTransformer.getR() > 1)
    {
        ui->component_list->addItem(QString("Transformer"));
    }
    if(elements_params_ptr->nodePOAmp.getR() > 1)
    {
        ui->component_list->addItem(QString("PO Amplifier"));
    }
   /* if(elements_params_ptr->nodePerfTrans.getR() > 0)
    {
        ui->component_list->addItem(QString("Perf Transistor"));
    }*/
}

void EditionElements::resetValue()
{
    ui->node_nm->setValue(1);
    ui->node_np->setValue(1);
    ui->node_km->setValue(1);
    ui->node_kp->setValue(1);
    ui->p0_value->setValue(0);
    ui->p1_value->setValue(0);
    ui->p2_value->setValue(0);
    ui->p3_value->setValue(0);
    ui->p4_value->setValue(0);
    ui->p5_value->setValue(0);
    ui->elenent_number->setValue(1);
}

void EditionElements::resistorTittle()
{
    ui->p0->setText(QString("Сопротивление, кОм"));
    ui->elenent_number->setMaximum(static_cast<int>(elements_params_ptr->nodeR.getR()));
    ui->elenent_number->setMinimum(1);
}

void EditionElements::caparisonTitle()
{
    ui->p0->setText(QString("Емкость, мкФ"));
    ui->elenent_number->setMaximum(static_cast<int>(elements_params_ptr->nodeC.getR()));
    ui->elenent_number->setMinimum(1);
}

void EditionElements::inductancesTitle()
{
    ui->p0->setText(QString("Индуктивность, Гн"));
    ui->elenent_number->setMaximum(static_cast<int>(elements_params_ptr->nodeL.getR()));
    ui->elenent_number->setMinimum(1);
}

void EditionElements::ITUNTitle()
{
    ui->p0->setText(QString("Коэффициент преобразования"));
    ui->elenent_number->setMaximum(static_cast<int>(elements_params_ptr->nodeITUN.getR()));
    ui->elenent_number->setMinimum(1);
}

void EditionElements::INUNTitle()
{
    ui->p0->setText(QString("Коэффициент преобразования"));
    ui->elenent_number->setMaximum(static_cast<int>(elements_params_ptr->nodeINUN.getR()));
    ui->elenent_number->setMinimum(1);
}

void EditionElements::ITUTTitle()
{
    ui->p0->setText(QString("Коэффициент преобразования"));
    ui->elenent_number->setMaximum(static_cast<int>(elements_params_ptr->nodeITUT.getR()));
    ui->elenent_number->setMinimum(1);
}

void EditionElements::INUTTitle()
{
    ui->p0->setText(QString("Коэффициент преобразования"));
    ui->elenent_number->setMaximum(static_cast<int>(elements_params_ptr->nodeINUT.getR()));
    ui->elenent_number->setMinimum(1);
}

void EditionElements::BPTransistorTitle()
{
    ui->nm_l->setText(QString("Эмитор"));
    ui->np_l->setText(QString("База"));
    ui->km_l->setText(QString("колектор"));
    ui->p0->setText(QString("Rb"));
    ui->p1->setText(QString("Re"));
    ui->p2->setText(QString("Rc"));
    ui->p3->setText(QString("Ce"));
    ui->p4->setText(QString("Cc"));
    ui->p5->setText(QString("bt"));
    ui->elenent_number->setMaximum(static_cast<int>(elements_params_ptr->nodeBPTrans.getR()));
    ui->elenent_number->setMinimum(1);
}

void EditionElements::UPTransistorTitle()
{
    ui->nm_l->setText(QString("nz"));
    ui->np_l->setText(QString("ns"));
    ui->km_l->setText(QString("ni"));
    ui->p0->setText(QString("Rc"));
    ui->p1->setText(QString("Czi"));
    ui->p2->setText(QString("Czs"));
    ui->p3->setText(QString("Csi"));
    ui->p4->setText(QString("S"));
    ui->elenent_number->setMaximum(static_cast<int>(elements_params_ptr->nodeUPTrans.getR()));
    ui->elenent_number->setMinimum(1);
}

void EditionElements::OperAmplifierTitle()
{
    ui->nm_l->setText(QString("n-"));
    ui->np_l->setText(QString("n+"));
    ui->km_l->setText(QString("k-"));
    ui->kp_l->setText(QString("k+"));
    ui->p0->setText(QString("Ri"));
    ui->p1->setText(QString("Ro"));
    ui->p2->setText(QString("mu"));
    ui->p3->setText(QString("ft"));
    ui->elenent_number->setMaximum(static_cast<int>(elements_params_ptr->nodeOperAmp.getR()));
    ui->elenent_number->setMinimum(1);
}

void EditionElements::TransformerTitle()
{
    ui->nm_l->setText(QString("n-"));
    ui->np_l->setText(QString("n+"));
    ui->km_l->setText(QString("k-"));
    ui->kp_l->setText(QString("k+"));
    ui->p0->setText(QString("R1"));
    ui->p1->setText(QString("R2"));
    ui->p2->setText(QString("L1"));
    ui->p3->setText(QString("L2"));
    ui->p4->setText(QString("M"));
    ui->elenent_number->setMaximum(static_cast<int>(elements_params_ptr->nodeTransformer.getR()));
    ui->elenent_number->setMinimum(1);
}

void EditionElements::POAmplifierTitle()
{
    ui->p0->hide();
    ui->p1->hide();
    ui->p2->hide();
    ui->p3->hide();
    ui->p4->hide();
    ui->p5->hide();
    ui->p0_value->hide();
    ui->p1_value->hide();
    ui->p2_value->hide();
    ui->p3_value->hide();
    ui->nm_l->setText(QString("n-"));
    ui->np_l->setText(QString("n+"));
    ui->km_l->setText(QString("k-"));
    ui->kp_l->setText(QString("k+"));
    ui->elenent_number->setMaximum(static_cast<int>(elements_params_ptr->nodePOAmp.getR()));
    ui->elenent_number->setMinimum(1);
}

void EditionElements::PerfTransistorTitle()
{
    ui->nm_l->setText(QString("Коллектор"));
    ui->np_l->setText(QString("База"));
    ui->km_l->setText(QString("Эмитор"));
    ui->p0->setText(QString("Коэффициент преобразования"));
    ui->p1->setText(QString("Коэффициент преобразования"));
    ui->p2->setText(QString("Коэффициент преобразования"));
    ui->p3->setText(QString("Коэффициент преобразования"));
    ui->p4->setText(QString("Коэффициент преобразования"));
    ui->elenent_number->setMaximum(static_cast<int>(elements_params_ptr->nodePerfTrans.getR()));
    ui->elenent_number->setMinimum(1);
}

void EditionElements::readResistorPar()
{
    ui->p0_value->setValue(elements_params_ptr->valueR[element_number][0]);
    ui->node_nm->setValue(elements_params_ptr->nodeR[element_number][1]);
    ui->node_np->setValue(elements_params_ptr->nodeR[element_number][0]);
}

void EditionElements::readCaparisonPar()
{
    ui->p0_value->setValue(elements_params_ptr->valueC[element_number][0]);
    ui->node_nm->setValue(elements_params_ptr->nodeC[element_number][1]);
    ui->node_np->setValue(elements_params_ptr->nodeC[element_number][0]);
}

void EditionElements::readInductancesPar()
{
    ui->p0_value->setValue(elements_params_ptr->valueL[element_number][0]);
    ui->node_nm->setValue(elements_params_ptr->nodeL[element_number][1]);
    ui->node_np->setValue(elements_params_ptr->nodeL[element_number][0]);
}

void EditionElements::readITUNPar()
{
    ui->p0_value->setValue(elements_params_ptr->valueITUN[element_number][0]);
    ui->node_nm->setValue(elements_params_ptr->nodeITUN[element_number][1]);
    ui->node_np->setValue(elements_params_ptr->nodeITUN[element_number][0]);
    ui->node_km->setValue(elements_params_ptr->nodeITUN[element_number][3]);
    ui->node_kp->setValue(elements_params_ptr->nodeITUN[element_number][2]);
}

void EditionElements::readINUNPar()
{
    ui->p0_value->setValue(elements_params_ptr->valueINUN[element_number][0]);
    ui->node_nm->setValue(elements_params_ptr->nodeINUN[element_number][1]);
    ui->node_np->setValue(elements_params_ptr->nodeINUN[element_number][0]);
    ui->node_km->setValue(elements_params_ptr->nodeINUN[element_number][3]);
    ui->node_kp->setValue(elements_params_ptr->nodeINUN[element_number][2]);
}

void EditionElements::readITUTPar()
{
    ui->p0_value->setValue(elements_params_ptr->valueITUT[element_number][0]);
    ui->node_nm->setValue(elements_params_ptr->nodeITUT[element_number][1]);
    ui->node_np->setValue(elements_params_ptr->nodeITUT[element_number][0]);
    ui->node_km->setValue(elements_params_ptr->nodeITUT[element_number][3]);
    ui->node_kp->setValue(elements_params_ptr->nodeITUT[element_number][2]);
}

void EditionElements::readINUTPar()
{
    ui->p0_value->setValue(elements_params_ptr->valueINUT[element_number][0]);
    ui->node_nm->setValue(elements_params_ptr->nodeINUT[element_number][1]);
    ui->node_np->setValue(elements_params_ptr->nodeINUT[element_number][0]);
    ui->node_km->setValue(elements_params_ptr->nodeINUT[element_number][3]);
    ui->node_kp->setValue(elements_params_ptr->nodeINUT[element_number][2]);
}

void EditionElements::readBPTransistorPar()
{
    ui->p0_value->setValue(elements_params_ptr->valueBPTrans[element_number][0]);
    ui->p1_value->setValue(elements_params_ptr->valueBPTrans[element_number][1]);
    ui->p2_value->setValue(elements_params_ptr->valueBPTrans[element_number][2]);
    ui->p3_value->setValue(elements_params_ptr->valueBPTrans[element_number][3]);
    ui->p4_value->setValue(elements_params_ptr->valueBPTrans[element_number][4]);
    ui->p5_value->setValue(elements_params_ptr->valueBPTrans[element_number][5]);
    ui->node_np->setValue(elements_params_ptr->nodeBPTrans[element_number][0]);
    ui->node_nm->setValue(elements_params_ptr->nodeBPTrans[element_number][1]);
    ui->node_km->setValue(elements_params_ptr->nodeBPTrans[element_number][2]);
}

void EditionElements::readUPTransistorPar()
{
    ui->p0_value->setValue(elements_params_ptr->valueBPTrans[element_number][0]);
    ui->p1_value->setValue(elements_params_ptr->valueBPTrans[element_number][1]);
    ui->p2_value->setValue(elements_params_ptr->valueBPTrans[element_number][2]);
    ui->p3_value->setValue(elements_params_ptr->valueBPTrans[element_number][3]);
    ui->p4_value->setValue(elements_params_ptr->valueBPTrans[element_number][4]);
    ui->node_np->setValue(elements_params_ptr->nodeBPTrans[element_number][0]);
    ui->node_nm->setValue(elements_params_ptr->nodeBPTrans[element_number][1]);
    ui->node_km->setValue(elements_params_ptr->nodeBPTrans[element_number][2]);
}

void EditionElements::readOperAmplifierPar()
{
    ui->p0_value->setValue(elements_params_ptr->valueOperAmp[element_number][0]);
    ui->p1_value->setValue(elements_params_ptr->valueOperAmp[element_number][1]);
    ui->p2_value->setValue(elements_params_ptr->valueOperAmp[element_number][2]);
    ui->p3_value->setValue(elements_params_ptr->valueOperAmp[element_number][3]);
    ui->node_nm->setValue(elements_params_ptr->nodeOperAmp[element_number][0]);
    ui->node_np->setValue(elements_params_ptr->nodeOperAmp[element_number][1]);
    ui->node_km->setValue(elements_params_ptr->nodeOperAmp[element_number][2]);
    ui->node_kp->setValue(elements_params_ptr->nodeOperAmp[element_number][3]);
}

void EditionElements::readTransformerPar()
{
    ui->p0_value->setValue(elements_params_ptr->valueTranformer[element_number][0]);
    ui->p1_value->setValue(elements_params_ptr->valueTranformer[element_number][1]);
    ui->p2_value->setValue(elements_params_ptr->valueTranformer[element_number][2]);
    ui->p3_value->setValue(elements_params_ptr->valueTranformer[element_number][3]);
    ui->node_nm->setValue(elements_params_ptr->nodeTransformer[element_number][0]);
    ui->node_np->setValue(elements_params_ptr->nodeTransformer[element_number][1]);
    ui->node_km->setValue(elements_params_ptr->nodeTransformer[element_number][2]);
    ui->node_kp->setValue(elements_params_ptr->nodeTransformer[element_number][3]);
}

void EditionElements::readPOAmplifierPar()
{
    ui->node_nm->setValue(elements_params_ptr->nodePOAmp[element_number][0]);
    ui->node_np->setValue(elements_params_ptr->nodePOAmp[element_number][1]);
    ui->node_km->setValue(elements_params_ptr->nodePOAmp[element_number][2]);
    ui->node_kp->setValue(elements_params_ptr->nodePOAmp[element_number][3]);
}

void EditionElements::readPerfTransistorPar()
{
    ui->p0_value->setValue(elements_params_ptr->valuePerfTrans[element_number][0]);
    ui->p1_value->setValue(elements_params_ptr->valuePerfTrans[element_number][1]);
    ui->p2_value->setValue(elements_params_ptr->valuePerfTrans[element_number][2]);
    ui->p3_value->setValue(elements_params_ptr->valuePerfTrans[element_number][3]);
    ui->p4_value->setValue(elements_params_ptr->valuePerfTrans[element_number][4]);
    ui->node_np->setValue(elements_params_ptr->nodePerfTrans[element_number][0]);
    ui->node_nm->setValue(elements_params_ptr->nodePerfTrans[element_number][1]);
    ui->node_km->setValue(elements_params_ptr->nodePerfTrans[element_number][2]);
}

void EditionElements::saveResistorPar()
{
    elements_params_ptr->valueR[element_number][0] = ui->p0_value->value();
    elements_params_ptr->nodeR[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeR[element_number][0] = ui->node_np->value();
}

void EditionElements::saveCaparisonPar()
{
    elements_params_ptr->valueC[element_number][0] = ui->p0_value->value();
    elements_params_ptr->nodeC[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeC[element_number][0] = ui->node_np->value();
}

void EditionElements::saveInductancesPar()
{
    elements_params_ptr->valueL[element_number][0] = ui->p0_value->value();
    elements_params_ptr->nodeL[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeL[element_number][0] = ui->node_np->value();
}

void EditionElements::saveITUNPar()
{
    elements_params_ptr->valueITUN[element_number][0] = ui->p0_value->value();
    elements_params_ptr->nodeITUN[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeITUN[element_number][0] = ui->node_np->value();
    elements_params_ptr->nodeITUN[element_number][3] = ui->node_km->value();
    elements_params_ptr->nodeITUN[element_number][2] = ui->node_kp->value();
}

void EditionElements::saveINUNPar()
{
    elements_params_ptr->valueINUN[element_number][0] = ui->p0_value->value();
    elements_params_ptr->nodeINUN[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeINUN[element_number][0] = ui->node_np->value();
    elements_params_ptr->nodeINUN[element_number][3] = ui->node_km->value();
    elements_params_ptr->nodeINUN[element_number][2] = ui->node_kp->value();
}

void EditionElements::saveITUTPar()
{
    elements_params_ptr->valueITUT[element_number][0] = ui->p0_value->value();
    elements_params_ptr->nodeITUT[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeITUT[element_number][0] = ui->node_np->value();
    elements_params_ptr->nodeITUT[element_number][3] = ui->node_km->value();
    elements_params_ptr->nodeITUT[element_number][2] = ui->node_kp->value();
}

void EditionElements::saveINUTPar()
{
    elements_params_ptr->valueINUT[element_number][0] = ui->p0_value->value();
    elements_params_ptr->nodeINUT[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeINUT[element_number][0] = ui->node_np->value();
    elements_params_ptr->nodeINUT[element_number][3] = ui->node_km->value();
    elements_params_ptr->nodeINUT[element_number][2] = ui->node_kp->value();
}

void EditionElements::saveBPTransistorPar()
{
    elements_params_ptr->valueBPTrans[element_number][0] = ui->p0_value->value();
    elements_params_ptr->valueBPTrans[element_number][1] = ui->p1_value->value();
    elements_params_ptr->valueBPTrans[element_number][2] = ui->p2_value->value();
    elements_params_ptr->valueBPTrans[element_number][3] = ui->p3_value->value();
    elements_params_ptr->valueBPTrans[element_number][4] = ui->p4_value->value();
    elements_params_ptr->valueBPTrans[element_number][5] = ui->p5_value->value();
    elements_params_ptr->nodeBPTrans[element_number][0] = ui->node_np->value();
    elements_params_ptr->nodeBPTrans[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeBPTrans[element_number][2] = ui->node_km->value();
}

void EditionElements::saveUPTransistorPar()
{
    elements_params_ptr->valueUPTrans[element_number][0] = ui->p0_value->value();
    elements_params_ptr->valueUPTrans[element_number][1] = ui->p1_value->value();
    elements_params_ptr->valueUPTrans[element_number][2] = ui->p2_value->value();
    elements_params_ptr->valueUPTrans[element_number][3] = ui->p3_value->value();
    elements_params_ptr->valueUPTrans[element_number][4] = ui->p4_value->value();
    elements_params_ptr->nodeUPTrans[element_number][0] = ui->node_np->value();
    elements_params_ptr->nodeUPTrans[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeUPTrans[element_number][2] = ui->node_km->value();
}

void EditionElements::saveOperAmplifierPar()
{
    elements_params_ptr->valueOperAmp[element_number][0] = ui->p0_value->value();
    elements_params_ptr->valueOperAmp[element_number][1] = ui->p1_value->value();
    elements_params_ptr->valueOperAmp[element_number][2] = ui->p2_value->value();
    elements_params_ptr->valueOperAmp[element_number][3] = ui->p3_value->value();
    elements_params_ptr->nodeOperAmp[element_number][0] = ui->node_nm->value();
    elements_params_ptr->nodeOperAmp[element_number][1] = ui->node_np->value();
    elements_params_ptr->nodeOperAmp[element_number][2] = ui->node_km->value();
    elements_params_ptr->nodeOperAmp[element_number][3] = ui->node_kp->value();
}

void EditionElements::saveTransformerPar()
{
    elements_params_ptr->valueTranformer[element_number][0] = ui->p0_value->value();
    elements_params_ptr->valueTranformer[element_number][1] = ui->p1_value->value();
    elements_params_ptr->valueTranformer[element_number][2] = ui->p2_value->value();
    elements_params_ptr->valueTranformer[element_number][3] = ui->p3_value->value();
    elements_params_ptr->nodeTransformer[element_number][0] = ui->node_nm->value();
    elements_params_ptr->nodeTransformer[element_number][1] = ui->node_np->value();
    elements_params_ptr->nodeTransformer[element_number][2] = ui->node_km->value();
    elements_params_ptr->nodeTransformer[element_number][3] = ui->node_kp->value();
}

void EditionElements::savePOAmplifierPar()
{
    elements_params_ptr->nodePOAmp[element_number][0] = ui->node_nm->value();
    elements_params_ptr->nodePOAmp[element_number][1] = ui->node_np->value();
    elements_params_ptr->nodePOAmp[element_number][2] = ui->node_km->value();
    elements_params_ptr->nodePOAmp[element_number][3] = ui->node_kp->value();
}

void EditionElements::savePerfTransistorPar()
{
    elements_params_ptr->valuePerfTrans[element_number][0] = ui->p0_value->value();
    elements_params_ptr->valuePerfTrans[element_number][1] = ui->p1_value->value();
    elements_params_ptr->valuePerfTrans[element_number][2] = ui->p2_value->value();
    elements_params_ptr->valuePerfTrans[element_number][3] = ui->p3_value->value();
    elements_params_ptr->valuePerfTrans[element_number][4] = ui->p4_value->value();
    elements_params_ptr->nodePerfTrans[element_number][0] = ui->node_np->value();
    elements_params_ptr->nodePerfTrans[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodePerfTrans[element_number][2] = ui->node_km->value();
}

void EditionElements::initPointer(std::shared_ptr<ElementsParams> &shptr)
{
    elements_params_ptr = shptr;
    ui->component_list->clear();
}

void EditionElements::on_component_list_itemClicked(QListWidgetItem *item)
{
    static std::vector<QString> vec = {"R", "C", "L", "ITUN", "INUN", "ITUT", "INUT", "BP Transistor", "UP Transistor", "Op Amplifier", "Transformer", "PO Amplifier"};
    if (item->text() == vec[0])
    {
        f = 0;
        element_id = 0;
    }
    else if (item->text() == vec[1])
    {
        f = 0;
        element_id = 1;
    }
    else if (item->text() == vec[2])
    {
        f = 0;
        element_id = 2;
    }
    else if (item->text() == vec[3])
    {
        f = 1;
        element_id = 3;
    }
    else if (item->text() == vec[4])
    {
        f = 1;
        element_id = 4;
    }
    else if (item->text() == vec[5])
    {
        f = 1;
        element_id = 5;
    }
    else if (item->text() == vec[6])
    {
        f = 1;
        element_id = 6;
    }
    else if (item->text() == vec[7])
    {
        f = 2;
        element_id = 7;
    }
    else if (item->text() == vec[8])
    {
        f = 3;
        element_id = 8;
    }
    else if (item->text() == vec[9])
    {
        f = 4;
        element_id = 9;
    }
    else if (item->text() == vec[10])
    {
        f = 4;
        element_id = 10;
    }
    else if (item->text() == vec[11])
    {
        f = 4;
        element_id = 11;
    }
    element_number = 1;
    ui->elenent_number->setValue(static_cast<int>(element_number));
    (this->*titles[element_id])();
    (this->*read_par[element_id])();
}

void EditionElements::on_exit_clicked()
{
    this->hide();
    emit showMainWindow();
}

void EditionElements::on_change_clicked()
{
    if (element_id < max_id)
    {
        (this->*save_par[element_id])();
    }
}

void EditionElements::on_elenent_number_valueChanged(int arg1)
{
    element_number = static_cast<size_t>(arg1 - 1);
    (this->*read_par[element_id])();
}
