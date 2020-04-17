#include "elementsparams.h"

ElementsParams::ElementsParams()
{

}

void ElementsParams::Init(size_t rc, size_t cc, size_t lc, size_t itunc, size_t inunc, size_t itutc, size_t inutc,
                          size_t bptrc, size_t uptrc, size_t oac, size_t tc, size_t poac, size_t ptrc)
{
    valueR.resize(rc + 1, 1);
    nodeR.resize(rc + 1, 2);

    valueC.resize(cc + 1, 1);
    nodeC.resize(cc + 1, 2);

    valueL.resize(lc + 1, 1);
    nodeL.resize(lc + 1, 2);

    valueITUN.resize(itunc + 1, 3);
    nodeITUN.resize(itunc + 1, 4);

    valueITUT.resize(itutc + 1, 3);
    nodeITUT.resize(itutc + 1, 4);

    valueINUN.resize(inunc + 1, 3);
    nodeINUN.resize(inunc + 1, 4);

    valueINUT.resize(inutc + 1, 3);
    nodeINUT.resize(inutc + 1, 4);

    valueBPTrans.resize(bptrc + 1, 6);
    nodeBPTrans.resize(bptrc + 1, 3);

    valueUPTrans.resize(uptrc + 1, 5);
    nodeUPTrans.resize(uptrc + 1, 3);

    valueOperAmp.resize(oac + 1, 4);
    nodeOperAmp.resize(oac + 1, 4);

    valueTranformer.resize(tc + 1, 4);
    nodeTransformer.resize(tc + 1, 4);

    valuePOAmp.resize(poac + 1, 4);
    nodePOAmp.resize(poac + 1, 4);

    valuePerfTrans.resize(ptrc + 1, 3);
    nodePerfTrans.resize(ptrc + 1, 3);
}

void ElementsParams::writeR(std::ofstream &out)
{
    out << valueR.getR() <<std::endl;
    for (size_t i = 1; i < valueR.getR(); ++i)
    {
        out << nodeR[i][0] << " " << nodeR[i][1] << " " << valueR[i][0] << std::endl;
    }
}

void ElementsParams::writeC(std::ofstream &out)
{
    out << valueC.getR() <<std::endl;
    for (size_t i = 1; i < valueC.getR(); ++i)
    {
        out << nodeC[i][0] << " " << nodeC[i][1] << " " << valueC[i][0] << std::endl;
    }
}

void ElementsParams::writeL(std::ofstream &out)
{
    out << valueL.getR() <<std::endl;
    for (size_t i = 1; i < valueL.getR(); ++i)
    {
        out << nodeL[i][0] << " " << nodeL[i][1] << " " << valueL[i][0] << std::endl;
    }
}

void ElementsParams::writeITUN(std::ofstream &out)
{
    out << valueITUN.getR() <<std::endl;
    for (size_t i = 1; i < valueITUN.getR(); ++i)
    {
        out << nodeITUN[i][0] << " " << nodeITUN[i][1] << " "
            << nodeITUN[i][2] << " " << nodeITUN[i][3] << " " << valueITUN[i][0]
            << " " << valueITUN[i][1] << " " << valueITUN[i][2] << std::endl;
    }
}

void ElementsParams::writeINUN(std::ofstream &out)
{
    out << valueINUN.getR() <<std::endl;
    for (size_t i = 1; i < valueINUN.getR(); ++i)
    {
        out << nodeINUN[i][0] << " " << nodeINUN[i][1] << " "
            << nodeINUN[i][2] << " " << nodeINUN[i][3] << " " << valueINUN[i][0]
            << " " << valueINUN[i][1] << " " << valueINUN[i][2] << std::endl;
    }
}

void ElementsParams::writeITUT(std::ofstream &out)
{
    out << valueITUT.getR() <<std::endl;
    for (size_t i = 1; i < valueITUN.getR(); ++i)
    {
        out << nodeITUT[i][0] << " " << nodeITUT[i][1] << " "
            << nodeITUT[i][2] << " " << nodeITUT[i][3] << " " << valueITUT[i][0]
            << " " << valueITUT[i][1] << " " << valueITUT[i][2] << std::endl;
    }
}

void ElementsParams::writeINUT(std::ofstream &out)
{
    out << valueINUT.getR() <<std::endl;
    for (size_t i = 1; i < valueITUN.getR(); ++i)
    {
        out << nodeINUT[i][0] << " " << nodeINUT[i][1] << " "
            << nodeINUT[i][2] << " " << nodeINUT[i][3] << " " << valueINUT[i][0]
            << " " << valueINUT[i][1] << " " << valueINUT[i][2] << std::endl;
    }
}

void ElementsParams::writeBPTrans(std::ofstream &out)
{
    out << valueBPTrans.getR() <<std::endl;
    for (size_t i = 1; i < valueITUN.getR(); ++i)
    {
        out << nodeBPTrans[i][0] << " " << nodeBPTrans[i][1] << " " << nodeBPTrans[i][2] << " " << valueBPTrans[i][0] << " " << valueBPTrans[i][1]
            << " " << valueBPTrans[i][2] << " " << valueBPTrans[i][3] << " " << valueBPTrans[i][4] << " " << valueBPTrans[i][5] << std::endl;
    }
}

void ElementsParams::writeUPTrans(std::ofstream &out)
{
    out << valueUPTrans.getR() <<std::endl;
    for (size_t i = 1; i < valueITUN.getR(); ++i)
    {
        out << nodeUPTrans[i][0] << " " << nodeUPTrans[i][1] << " " << nodeUPTrans[i][2] << " " << valueUPTrans[i][0] << " " << valueUPTrans[i][1]
            << " " << valueUPTrans[i][2] << " " << valueUPTrans[i][3] << " " << valueUPTrans[i][4] << std::endl;
    }
}

void ElementsParams::writeOperAmp(std::ofstream &out)
{
    out << valueOperAmp.getR() <<std::endl;
    for (size_t i = 1; i < valueOperAmp.getR(); ++i)
    {
        out << nodeOperAmp[i][0] << " " << nodeOperAmp[i][1] << " " << nodeOperAmp[i][2] << " " << nodeOperAmp[i][3] << " "
            << valueOperAmp[i][0] << " " << valueOperAmp[i][1] << " " << valueOperAmp[i][2] << " " << valueOperAmp[i][3] << std::endl;
    }
}

void ElementsParams::writeTransformer(std::ofstream &out)
{
    out << valueTranformer.getR() <<std::endl;
    for (size_t i = 1; i < valueTranformer.getR(); ++i)
    {
        out << nodeTransformer[i][0] << " " << nodeTransformer[i][1] << " " << nodeTransformer[i][2] << " " << nodeTransformer[i][3] << " "
            << valueTranformer[i][0] << " " << valueTranformer[i][1] << " " << valueTranformer[i][2] << " " << valueTranformer[i][3] << std::endl;
    }
}

void ElementsParams::writePOAmp(std::ofstream &out)
{
    out << valuePOAmp.getR() << std::endl;
    for (size_t i = 1; i < valuePOAmp.getR(); ++i)
    {
        out << nodePOAmp[i][0] << " " << nodePOAmp[i][1] << " " << nodePOAmp[i][2] << " " << nodePOAmp[i][3] << std::endl;
    }
}

void ElementsParams::writePerfTrans(std::ofstream &out)
{
    out << valuePerfTrans.getR() <<std::endl;
    for (size_t i = 1; i < valuePerfTrans.getR(); ++i)
    {
        out << nodePerfTrans[i][0] << " " << nodePerfTrans[i][1] << " " << nodePerfTrans[i][2] << " " << valuePerfTrans[i][0] << " " << valuePerfTrans[i][1]
            << " " << valuePerfTrans[i][2] << " " << valuePerfTrans[i][3] << " " << valuePerfTrans[i][4] << std::endl;
    }
}

void ElementsParams::WritePerfectTransformer(std::ofstream &out)
{
    out << valuePerfectTransformer.getR() <<std::endl;
    for (size_t i = 1; i < valuePerfectTransformer.getR(); ++i)
    {
        out << nodePerfectTransformer[i][0] << " " << nodePerfectTransformer[i][1] << " " << nodePerfectTransformer[i][2] << " " << nodePerfectTransformer[i][3]
            << " " << valuePerfectTransformer[i][0] << std::endl;
    }
}

void ElementsParams::readR(std::ifstream &in)
{
    size_t size;
    in >> size;
    if (size > 0)
    {
        valueR.resize(size, 1);
        nodeR.resize(size, 2);
        for (size_t i = 1; i < size; ++i)
        {
            in >> nodeR[i][0] >> nodeR[i][1] >> valueR[i][0];
        }
    }
}

void ElementsParams::readC(std::ifstream &in)
{
    size_t size;
    in >> size;
    if (size > 0)
    {
        valueC.resize(size, 1);
        nodeC.resize(size, 2);
        for (size_t i = 1; i < size; ++i)
        {
            in >> nodeC[i][0] >> nodeC[i][1] >> valueC[i][0];
        }
    }
}

void ElementsParams::readL(std::ifstream &in)
{
    size_t size;
    in >> size;
    if (size > 0)
    {
        valueL.resize(size, 1);
        nodeL.resize(size, 2);
        for (size_t i = 1; i < size; ++i)
        {
            in >> nodeL[i][0] >> nodeL[i][1] >> valueL[i][0];
        }
    }
}

void ElementsParams::readITUN(std::ifstream &in)
{
    size_t size;
    in >> size;
    if (size > 0)
    {
        valueITUN.resize(size, 1);
        nodeITUN.resize(size, 4);
        for (size_t i = 1; i < size; ++i)
        {
            in >> nodeITUN[i][0] >> nodeITUN[i][1] >> nodeITUN[i][2] >> nodeITUN[i][3] >> valueITUN[i][0] >> valueITUN[i][1] >> valueITUN[i][2];
        }
    }
}

void ElementsParams::readINUN(std::ifstream &in)
{
    size_t size;
    in >> size;
    if (size > 0)
    {
        valueINUN.resize(size, 1);
        nodeINUN.resize(size, 4);
        for (size_t i = 1; i < size; ++i)
        {
            in >> nodeINUN[i][0] >> nodeINUN[i][1] >> nodeINUN[i][2] >> nodeINUN[i][3] >> valueINUN[i][0] >> valueINUN[i][1] >> valueINUN[i][2];
        }
    }
}

void ElementsParams::readITUT(std::ifstream &in)
{
    size_t size;
    in >> size;
    if (size > 0)
    {
        valueITUT.resize(size, 1);
        nodeITUT.resize(size, 4);
        for (size_t i = 1; i < size; ++i)
        {
            in >> nodeITUT[i][0] >> nodeITUT[i][1] >> nodeITUT[i][2] >> nodeITUT[i][3] >> valueITUT[i][0] >> valueITUT[i][1] >> valueITUT[i][2];
        }
    }
}

void ElementsParams::readINUT(std::ifstream &in)
{
    size_t size;
    in >> size;
    if (size > 0)
    {
        valueINUT.resize(size, 1);
        nodeINUT.resize(size, 4);
        for (size_t i = 1; i < size; ++i)
        {
            in >> nodeINUT[i][0] >> nodeINUT[i][1] >> nodeINUT[i][2] >> nodeINUT[i][3] >> valueINUT[i][0] >> valueINUT[i][1] >> valueINUT[i][2];
        }
    }
}

void ElementsParams::readBPTrans(std::ifstream &in)
{
    size_t size;
    in >> size;
    if (size > 0)
    {
        valueBPTrans.resize(size, 6);
        nodeBPTrans.resize(size, 3);
        for (size_t i = 1; i < size; ++i)
        {
            in >> nodeBPTrans[i][0] >> nodeBPTrans[i][1] >> nodeBPTrans[i][2] >> valueBPTrans[i][0] >> valueBPTrans[i][1]
                                    >> valueBPTrans[i][2] >> valueBPTrans[i][3] >> valueBPTrans[i][4] >> valueBPTrans[i][5];
        }
    }
}

void ElementsParams::readUPTrans(std::ifstream &in)
{
    size_t size;
    in >> size;
    if (size > 0)
    {
        nodeUPTrans.resize(size, 3);
        valueUPTrans.resize(size, 5);
        for (size_t i = 1; i < size; ++i)
        {
            in >> nodeUPTrans[i][0] >> nodeUPTrans[i][1] >> nodeUPTrans[i][2] >> valueBPTrans[i][0] >> valueBPTrans[i][1]
                                    >> valueUPTrans[i][2] >> valueUPTrans[i][3] >> valueUPTrans[i][4];
        }
    }
}

void ElementsParams::readOperAmp(std::ifstream &in)
{
    size_t size;
    in >> size;
    if (size > 0)
    {
        nodeOperAmp.resize(size, 4);
        valueOperAmp.resize(size, 4);
        for (size_t i = 1; i < size; ++i)
        {
            in >> nodeOperAmp[i][0] >> nodeOperAmp[i][1] >> nodeOperAmp[i][2] >> nodeOperAmp[i][3]
                    >> valueOperAmp[i][0] >> valueOperAmp[i][1] >> valueOperAmp[i][2] >> valueOperAmp[i][3];
        }
    }
}

void ElementsParams::readTransformer(std::ifstream &in)
{
    size_t size;
    in >> size;
    if (size > 0)
    {
        nodeTransformer.resize(size, 4);
        valueTranformer.resize(size, 4);
        for (size_t i = 1; i < size; ++i)
        {
            in >> nodeTransformer[i][0] >> nodeTransformer[i][1] >> nodeTransformer[i][2] >> nodeTransformer[i][3]
                    >> valueTranformer[i][0] >> valueTranformer[i][1] >> valueTranformer[i][2] >> valueTranformer[i][3];
        }
    }
}

void ElementsParams::readPOAmp(std::ifstream &in)
{
    size_t size;
    in >> size;
    if (size > 0)
    {
        nodePOAmp.resize(size, 4);
        valuePOAmp.resize(size, 4);
        for (size_t i = 1; i < size; ++i)
        {
            in >> nodePOAmp[i][0] >> nodePOAmp[i][1] >> nodePOAmp[i][2] >> nodePOAmp[i][3];
        }

    }
}

void ElementsParams::readPerfTrans(std::ifstream &in)
{
    size_t size;
    in >> size;
    if (size > 0)
    {
        nodePerfTrans.resize(size, 3);
        valuePerfTrans.resize(size, 5);
        for (size_t i = 1; i < size; ++i)
        {
            in >> nodePerfTrans[i][0] >> nodePerfTrans[i][1] >> nodePerfTrans[i][2] >> valuePerfTrans[i][0]
                    >> valuePerfTrans[i][1] >> valuePerfTrans[i][2] >> valuePerfTrans[i][3] >> valuePerfTrans[i][4];
        }
    }
}

void ElementsParams::readPerfectTransformer(std::ifstream &in)
{
    size_t size;
    in >> size;
    if (size > 0)
    {
        nodePerfectTransformer.resize(size, 4);
        valuePerfectTransformer.resize(size, 1);
        for (size_t i = 1; i < size; ++i)
        {
            in >> nodePerfectTransformer[i][0] >> nodePerfectTransformer[i][1] >> nodePerfectTransformer[i][2] >> nodePerfectTransformer[i][2]
                    >> valuePerfectTransformer[i][0];
        }
    }
}
