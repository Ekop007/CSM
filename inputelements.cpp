#include "inputelements.h"
#include "ui_inputelements.h"

InputElements::InputElements(QWidget *parent) :
    QDialog(parent), elem({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
    ui(new Ui::InputElements), element_number(1), element_id(0),
    max_id(13), width1(380), width2(720), f(0)
{
    ui->setupUi(this);
    ui->p1->hide();
    ui->p2->hide();
    ui->p3->hide();
    ui->p1_value->hide();
    ui->p2_value->hide();
    ui->p3_value->hide();

    titles[0] = &InputElements::resistorTittle;
    titles[1] = &InputElements::caparisonTitle;
    titles[2] = &InputElements::inductancesTitle;
    titles[3] = &InputElements::ITUNTitle;
    titles[4] = &InputElements::INUNTitle;
    titles[5] = &InputElements::ITUTTitle;
    titles[6] = &InputElements::INUTTitle;
    titles[7] = &InputElements::BPTransistorTitle;
    titles[8] = &InputElements::UPTransistorTitle;
    titles[9] = &InputElements::OperAmplifierTitle;
    titles[10] = &InputElements::TransformerTitle;
    titles[11] = &InputElements::POAmplifierTitle;
    titles[12] = &InputElements::PerfectTransformerTitle;

    read_par[0] = &InputElements::resistorPar;
    read_par[1] = &InputElements::caparisonPar;
    read_par[2] = &InputElements::inductancesPar;
    read_par[3] = &InputElements::ITUNPar;
    read_par[4] = &InputElements::INUNPar;
    read_par[5] = &InputElements::ITUTPar;
    read_par[6] = &InputElements::INUTPar;
    read_par[7] = &InputElements::BPTransistorPar;
    read_par[8] = &InputElements::UPTransistorPar;
    read_par[9] = &InputElements::OperAmplifierPar;
    read_par[10] = &InputElements::TransformerPar;
    read_par[11] = &InputElements::POAmplifierPar;
    read_par[12] = &InputElements::PerfectTransformerPar;

    this->move(300, 200);
    resetValue();
//    init();
    // Изменение имени окна и наименования элемента цепи

    // x = 120, y = 240 - button
    //     300      250
}

InputElements::~InputElements()
{
    delete ui;
}

void InputElements::setPtr(std::shared_ptr<ElementsParams> &ptr)
{
    elements_params_ptr = ptr;
}

void InputElements::setMaxId(std::size_t mi)
{
    max_id = mi;
}

void InputElements::init()
{
    ui->node_km->setMaximum(static_cast<int>(elements_params_ptr->maxnodes));
    ui->node_kp->setMaximum(static_cast<int>(elements_params_ptr->maxnodes));
    ui->node_nm->setMaximum(static_cast<int>(elements_params_ptr->maxnodes));
    ui->node_np->setMaximum(static_cast<int>(elements_params_ptr->maxnodes));
    element_id = 0;
    if (elements_params_ptr->nodeR.getR() == 1)
    {
        element_id +=1;
    }
    else
    {
        (this->*titles[element_id])();
        return;
    }
    if (elements_params_ptr->nodeC.getR() == 1)
    {
        element_id +=1;
    }
    else
    {
        (this->*titles[element_id])();
        return;
    }
    if (elements_params_ptr->nodeL.getR() == 1)
    {
        element_id +=1;
    }
    else
    {
        (this->*titles[element_id])();
        return;
    }
    if (elements_params_ptr->nodeITUN.getR() == 1)
    {
        element_id +=1;
    }
    else
    {
        (this->*titles[element_id])();
        return;
    }
    if (elements_params_ptr->nodeINUN.getR() == 1)
    {
        element_id +=1;
    }
    else
    {
        (this->*titles[element_id])();
        return;
    }
    if (elements_params_ptr->nodeITUT.getR() == 1)
    {
        element_id +=1;
    }
    else
    {
        return;
    }
    if (elements_params_ptr->nodeINUT.getR() == 1)
    {
        element_id +=1;
    }
    else
    {
        (this->*titles[element_id])();
        return;
    }
    if (elements_params_ptr->nodeBPTrans.getR() == 1)
    {
        element_id +=1;
    }
    else
    {
        (this->*titles[element_id])();
        return;
    }
    if (elements_params_ptr->nodeUPTrans.getR() == 1)
    {
        element_id +=1;
    }
    else
    {
        (this->*titles[element_id])();
        return;
    }
    if (elements_params_ptr->nodeOperAmp.getR() == 1)
    {
        element_id +=1;
    }
    else
    {
        (this->*titles[element_id])();
        return;
    }
    if (elements_params_ptr->nodeTransformer.getR() == 1)
    {
        element_id +=1;
    }
    else
    {
        (this->*titles[element_id])();
        return;
    }
    if (elements_params_ptr->nodePOAmp.getR() == 1)
    {
        element_id +=1;
    }
    else
    {
        (this->*titles[element_id])();
        return;
    }
    if (elements_params_ptr->nodePerfTrans.getR() == 1)
    {
        element_id +=1;
    }
    else
    {
        (this->*titles[element_id])();
        return;
    }
    if (element_id < max_id)
    {
        (this->*titles[element_id])();
    }
}

void InputElements::check()
{
    while (element_id < max_id)
    {
        switch (element_id)
        {
            case 0:
            if (elements_params_ptr->nodeR.getR() == 1)
            {
                element_id +=1;
            }
            else
            {
                (this->*titles[element_id])();
                return;
            }
            break;

            case 1:
            if (elements_params_ptr->nodeC.getR() == 1)
            {
                element_id +=1;
            }
            else
            {
                (this->*titles[element_id])();
                return;
            }
            break;

            case 2:
            if (elements_params_ptr->nodeL.getR() == 1)
            {
                element_id +=1;
            }
            else
            {
                (this->*titles[element_id])();
                return;
            }
            break;

            case 3:
            if (elements_params_ptr->nodeITUN.getR() == 1)
            {
                element_id +=1;
            }
            else
            {
                (this->*titles[element_id])();
                return;
            }
            break;

            case 4:
            if (elements_params_ptr->nodeINUN.getR() == 1)
            {
                element_id +=1;
            }
            else
            {
                (this->*titles[element_id])();
                return;
            }
            break;

            case 5:
            if (elements_params_ptr->nodeITUT.getR() == 1)
            {
                element_id +=1;
            }
            else
            {
                return;
            }
            break;

            case 6:
            if (elements_params_ptr->nodeINUT.getR() == 1)
            {
                element_id +=1;
            }
            else
            {
                (this->*titles[element_id])();
                return;
            }
            break;

            case 7:
            if (elements_params_ptr->nodeBPTrans.getR() == 1)
            {
                element_id +=1;
            }
            else
            {
                (this->*titles[element_id])();
                return;
            }
            break;

            case 8:
            if (elements_params_ptr->nodeUPTrans.getR() == 1)
            {
                element_id +=1;
            }
            else
            {
                (this->*titles[element_id])();
                return;
            }
            break;

            case 9:
            if (elements_params_ptr->nodeOperAmp.getR() == 1)
            {
                element_id +=1;
            }
            else
            {
                (this->*titles[element_id])();
                return;
            }
            break;

            case 10:
            if (elements_params_ptr->nodeTransformer.getR() == 1)
            {
                element_id +=1;
            }
            else
            {
                (this->*titles[element_id])();
                return;
            }
            break;

            case 11:
            if (elements_params_ptr->nodePOAmp.getR() == 1)
            {
                element_id +=1;
            }
            else
            {
                (this->*titles[element_id])();
                return;
            }
            break;

            case 12:
            if (elements_params_ptr->nodePerfectTransformer.getR() == 1)
            {
                element_id +=1;
            }
            else
            {
                (this->*titles[element_id])();
                return;
            }
            break;

            default:
            element_id +=1;
            break;
        }
    }
}

void InputElements::resetValue()
{
    str << element_number;
    ui->node_nm->setValue(0);
    ui->node_np->setValue(0);
    ui->node_km->setValue(0);
    ui->node_kp->setValue(0);
    ui->p0_value->setValue(0);
    ui->p1_value->setValue(0);
    ui->p2_value->setValue(0);
    ui->p3_value->setValue(0);
    ui->p4_value->setValue(0);
    ui->p5_value->setValue(0);
    ui->element_number->setText(QString(str.str().c_str()));
    str.str("");
}

void InputElements::resetSize()
{
    switch (f)
    {
    case 0: // R L C
        if (this->width() != width1)
        {
            this->resize(width1, this->height());
        }
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
        ui->next_element->move(120, 240);
        break;

    case 1: // I N/T
        if (this->width() != width2)
        {
            this->resize(width2, this->height());
        }
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
        ui->next_element->move(300, 250);
        break;

    case 2: // BP trans
        if (this->width() != width2)
        {
            this->resize(width2, this->height());
        }
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
        ui->next_element->move(300, 250);
        break;
    case 3: // UP trans || Perf trans
        if (this->width() != width2)
        {
            this->resize(width2, this->height());
        }
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
        ui->next_element->move(300, 250);
        break;
    case 4: // transformer || amplifier
        if (this->width() != width2)
        {
            this->resize(width2, this->height());
        }
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
        ui->node_kp->show();
        ui->next_element->move(300, 250);
        break;
    case 5: // transformer || amplifier
        if (this->width() != width2)
        {
            this->resize(width2, this->height());
        }
        ui->p0->show();
        ui->p0_value->show();
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
        ui->km_l->show();
        ui->kp_l->show();
        ui->node_km->show();
        ui->node_kp->show();
        ui->next_element->move(300, 250);
        break;
    }
}

void InputElements::resistorTittle()
{
    f = 0;
    resetSize();
    this->setWindowTitle(QString("R"));
    ui->name_element->setText(QString("R"));
    ui->p0->setText(QString("Сопротивление, кОм"));
}

void InputElements::caparisonTitle()
{
    f = 0;
    resetSize();
    this->setWindowTitle(QString("C"));
    ui->name_element->setText(QString("C"));
    ui->p0->setText(QString("Емкость, мкФ"));
}

void InputElements::inductancesTitle()
{
    f = 0;
    resetSize();
    this->setWindowTitle(QString("L"));
    ui->name_element->setText(QString("L"));
    ui->p0->setText(QString("Индуктивность, Гн"));
}

void InputElements::ITUNTitle()
{
    f = 1;
    resetSize();
    this->setWindowTitle(QString("ITUN"));
    ui->name_element->setText(QString("ITUN"));
    ui->p0->setText(QString("Коэффициент преобразования"));
    ui->p1->setText(QString("Константа времени T1"));
    ui->p2->setText(QString("Константа времени T2"));
    // 340 - ширина
}

void InputElements::INUNTitle()
{
    f = 1;
    resetSize();
    this->setWindowTitle(QString("INUN"));
    ui->name_element->setText(QString("INUN"));
    ui->p0->setText(QString("Коэффициент преобразования"));
    ui->p1->setText(QString("Константа времени T1"));
    ui->p2->setText(QString("Константа времени T2"));
}

void InputElements::ITUTTitle()
{
    f = 1;
    resetSize();
    this->setWindowTitle(QString("ITUT"));
    ui->name_element->setText(QString("ITUT"));
    ui->p0->setText(QString("Коэффициент преобразования"));
    ui->p1->setText(QString("Константа времени T1"));
    ui->p2->setText(QString("Константа времени T2"));
    // 720 - ширина
}

void InputElements::INUTTitle()
{
    f = 1;
    resetSize();
    this->setWindowTitle(QString("INUT"));
    ui->name_element->setText(QString("INUT"));
    ui->p0->setText(QString("Коэффициент преобразования"));
    ui->p1->setText(QString("Константа времени T1"));
    ui->p2->setText(QString("Константа времени T2"));
}

void InputElements::BPTransistorTitle()
{
    f = 2;
    resetSize();
    this->setWindowTitle(QString("Биполярный транзистор"));
    ui->name_element->setText(QString("Биполярный транзистор"));
    ui->nm_l->setText(QString("Эмитор"));
    ui->np_l->setText(QString("База"));
    ui->km_l->setText(QString("колектор"));
    ui->p0->setText(QString("Rb"));
    ui->p1->setText(QString("Re"));
    ui->p2->setText(QString("Rc"));
    ui->p3->setText(QString("Ce"));
    ui->p4->setText(QString("Cc"));
    ui->p5->setText(QString("bt"));
}

void InputElements::UPTransistorTitle()
{
    f = 3;
    resetSize();
    this->setWindowTitle(QString("Однополярный транзистор"));
    ui->name_element->setText(QString("Однополярный транзистор"));
    ui->nm_l->setText(QString("nz"));
    ui->np_l->setText(QString("ns"));
    ui->km_l->setText(QString("ni"));
    ui->p0->setText(QString("Rc"));
    ui->p1->setText(QString("Czi"));
    ui->p2->setText(QString("Czs"));
    ui->p3->setText(QString("Csi"));
    ui->p4->setText(QString("S"));
}

void InputElements::OperAmplifierTitle()
{
    f = 4;
    resetSize();
    this->setWindowTitle(QString("Операционный усилитель"));
    ui->nm_l->setText(QString("n-"));
    ui->np_l->setText(QString("n+"));
    ui->km_l->setText(QString("k-"));
    ui->kp_l->setText(QString("k+"));
    ui->p0->setText(QString("Ri"));
    ui->p1->setText(QString("Ro"));
    ui->p2->setText(QString("mu"));
    ui->p3->setText(QString("ft"));

}

void InputElements::TransformerTitle()
{
    f = 4;
    resetSize();
    this->setWindowTitle(QString("Трансформатор"));
    ui->nm_l->setText(QString("n-"));
    ui->np_l->setText(QString("n+"));
    ui->km_l->setText(QString("k-"));
    ui->kp_l->setText(QString("k+"));
    ui->p0->setText(QString("R1"));
    ui->p1->setText(QString("R2"));
    ui->p2->setText(QString("L1"));
    ui->p3->setText(QString("L2"));
    ui->p4->setText(QString("M"));

}

void InputElements::POAmplifierTitle()
{
    f = 4;
    resetSize();
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
    this->setWindowTitle(QString("Идеальный усилитель"));
    ui->nm_l->setText(QString("n-"));
    ui->np_l->setText(QString("n+"));
    ui->km_l->setText(QString("k-"));
    ui->kp_l->setText(QString("k+"));
}

void InputElements::PerfTransistorTitle()
{
    f = 1;
    resetSize();
    ui->p0->show();
    ui->p1->hide();
    ui->p2->hide();
    ui->p3->hide();
    ui->p4->hide();
    ui->p5->hide();
    ui->p0_value->show();
    ui->p1_value->hide();
    ui->p2_value->hide();
    ui->p3_value->hide();
    ui->p4_value->hide();
    ui->p5_value->hide();
    this->setWindowTitle(QString("Идеальный трансформатор"));
    ui->name_element->setText(QString("Идеальный трансформатор"));
    ui->nm_l->setText(QString("n-"));
    ui->np_l->setText(QString("n+"));
    ui->km_l->setText(QString("k-"));
    ui->kp_l->setText(QString("k+"));
    ui->p0->setText(QString("Коэффициент преобразования"));
    ui->p1->setText(QString("Коэффициент преобразования"));
    ui->p2->setText(QString("Коэффициент преобразования"));
    ui->p3->setText(QString("Коэффициент преобразования"));
    ui->p4->setText(QString("Коэффициент преобразования"));
}

void InputElements::PerfectTransformerTitle()
{
    f = 1;
    resetSize();
    ui->p0->show();
    ui->p1->hide();
    ui->p2->hide();
    ui->p3->hide();
    ui->p4->hide();
    ui->p5->hide();
    ui->p0_value->show();
    ui->p1_value->hide();
    ui->p2_value->hide();
    ui->p3_value->hide();
    ui->p4_value->hide();
    ui->p5_value->hide();
    this->setWindowTitle(QString("Идеальный транзистор"));
    ui->name_element->setText(QString("Идеальный транзистор"));
    ui->nm_l->setText(QString("n-"));
    ui->np_l->setText(QString("n+"));
    ui->kp_l->setText(QString("k+"));
    ui->km_l->setText(QString("k-"));
    ui->p0->setText(QString("Коэффициент преобразования"));
}

void InputElements::resistorPar()
{
    elements_params_ptr->valueR[element_number][0] = ui->p0_value->value();
    elements_params_ptr->nodeR[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeR[element_number][0] = ui->node_np->value();
}

void InputElements::caparisonPar()
{
    elements_params_ptr->valueC[element_number][0] = ui->p0_value->value();
    elements_params_ptr->nodeC[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeC[element_number][0] = ui->node_np->value();
}

void InputElements::inductancesPar()
{
    elements_params_ptr->valueL[element_number][0] = ui->p0_value->value();
    elements_params_ptr->nodeL[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeL[element_number][0] = ui->node_np->value();
}

void InputElements::ITUNPar()
{
    elements_params_ptr->valueITUN[element_number][0] = ui->p0_value->value();
    elements_params_ptr->valueITUN[element_number][1] = ui->p1_value->value();
    elements_params_ptr->valueITUN[element_number][2] = ui->p2_value->value();
    elements_params_ptr->nodeITUN[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeITUN[element_number][0] = ui->node_np->value();
    elements_params_ptr->nodeITUN[element_number][3] = ui->node_km->value();
    elements_params_ptr->nodeITUN[element_number][2] = ui->node_kp->value();
}

void InputElements::INUNPar()
{
    elements_params_ptr->valueINUN[element_number][0] = ui->p0_value->value();
    elements_params_ptr->valueINUN[element_number][1] = ui->p1_value->value();
    elements_params_ptr->valueINUN[element_number][2] = ui->p2_value->value();
    elements_params_ptr->nodeINUN[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeINUN[element_number][0] = ui->node_np->value();
    elements_params_ptr->nodeINUN[element_number][3] = ui->node_km->value();
    elements_params_ptr->nodeINUN[element_number][2] = ui->node_kp->value();
}

void InputElements::ITUTPar()
{
    elements_params_ptr->valueITUT[element_number][0] = ui->p0_value->value();
    elements_params_ptr->valueITUT[element_number][1] = ui->p1_value->value();
    elements_params_ptr->valueITUT[element_number][2] = ui->p2_value->value();
    elements_params_ptr->nodeITUT[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeITUT[element_number][0] = ui->node_np->value();
    elements_params_ptr->nodeITUT[element_number][3] = ui->node_km->value();
    elements_params_ptr->nodeITUT[element_number][2] = ui->node_kp->value();
}

void InputElements::INUTPar()
{
    elements_params_ptr->valueINUT[element_number][0] = ui->p0_value->value();
    elements_params_ptr->valueINUT[element_number][1] = ui->p1_value->value();
    elements_params_ptr->valueINUT[element_number][2] = ui->p2_value->value();
    elements_params_ptr->nodeINUT[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodeINUT[element_number][0] = ui->node_np->value();
    elements_params_ptr->nodeINUT[element_number][3] = ui->node_km->value();
    elements_params_ptr->nodeINUT[element_number][2] = ui->node_kp->value();
}

void InputElements::BPTransistorPar()
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

void InputElements::UPTransistorPar()
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

void InputElements::OperAmplifierPar()
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

void InputElements::TransformerPar()
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

void InputElements::POAmplifierPar()
{
   /* elements_params_ptr->valueBPTrans[element_number][0] = ui->p0_value->value();
    elements_params_ptr->valueBPTrans[element_number][1] = ui->p1_value->value();
    elements_params_ptr->valueBPTrans[element_number][2] = ui->p2_value->value();
    elements_params_ptr->valueBPTrans[element_number][3] = ui->p3_value->value();*/
    elements_params_ptr->nodePOAmp[element_number][0] = ui->node_nm->value();
    elements_params_ptr->nodePOAmp[element_number][1] = ui->node_np->value();
    elements_params_ptr->nodePOAmp[element_number][2] = ui->node_km->value();
    elements_params_ptr->nodePOAmp[element_number][3] = ui->node_kp->value();
}

void InputElements::PerfTransistorPar()
{
    elements_params_ptr->valuePerfectTransformer[element_number][0] = ui->p0_value->value();
    elements_params_ptr->valuePerfectTransformer[element_number][1] = ui->p1_value->value();
    elements_params_ptr->valuePerfectTransformer[element_number][2] = ui->p2_value->value();
    elements_params_ptr->valuePerfectTransformer[element_number][3] = ui->p3_value->value();
    elements_params_ptr->valuePerfectTransformer[element_number][4] = ui->p4_value->value();
    elements_params_ptr->nodePerfectTransformer[element_number][0] = ui->node_np->value();
    elements_params_ptr->nodePerfectTransformer[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodePerfectTransformer[element_number][2] = ui->node_km->value();
}

void InputElements::PerfectTransformerPar()
{
    elements_params_ptr->valuePerfectTransformer[element_number][0] = ui->p0_value->value();
    elements_params_ptr->nodePerfectTransformer[element_number][0] = ui->node_np->value();
    elements_params_ptr->nodePerfectTransformer[element_number][1] = ui->node_nm->value();
    elements_params_ptr->nodePerfectTransformer[element_number][2] = ui->node_kp->value();
    elements_params_ptr->nodePerfectTransformer[element_number][3] = ui->node_km->value();
}


void InputElements::on_next_element_clicked()
{
    this->hide();
    /* Здесь считывается информация  в массив */
    (this->*read_par[element_id])();
    if (element_number < elem[element_id])
    {
        ++element_number;
        resetValue();
        this->show();
    }
    else
    {
        element_number = 1;
        ++element_id;
        check();
        if (element_id >= max_id)
        {
            element_id = 1;
            element_number = 0;
            emit showMainWindow();
        }
        else
        {
            resetValue();
            // Изменение имени окна и наименования элемента цепи
            (this->*titles[element_id])();
            this->show();
        }
    }
}
