#ifndef ELEMENTSPARAMS_H
#define ELEMENTSPARAMS_H

#include <array>
#include <fstream>
#include "matrix.h"

namespace Cosnst_Values
{
    std::size_t const array_size = 13;
}


struct ElementsParams
{
    ElementsParams();
    void Init(size_t rc, size_t cc, size_t lc, size_t itunc, size_t inunc, size_t itutc, size_t inutc,
              size_t bptrc, size_t uptrc, size_t oac, size_t tc, size_t poac, size_t ptrc);
    void writeR(std::ofstream &out);
    void writeC(std::ofstream &out);
    void writeL(std::ofstream &out);
    void writeITUN(std::ofstream &out);
    void writeINUN(std::ofstream &out);
    void writeITUT(std::ofstream &out);
    void writeINUT(std::ofstream &out);
    void writeBPTrans(std::ofstream &out);
    void writeUPTrans(std::ofstream &out);
    void writeOperAmp(std::ofstream &out);
    void writeTransformer(std::ofstream &out);
    void writePOAmp(std::ofstream &out);
    void writePerfTrans(std::ofstream &out);
    void readR(std::ifstream &in);
    void readC(std::ifstream &in);
    void readL(std::ifstream &in);
    void readITUN(std::ifstream &in);
    void readINUN(std::ifstream &in);
    void readITUT(std::ifstream &in);
    void readINUT(std::ifstream &in);
    void readBPTrans(std::ifstream &in);
    void readUPTrans(std::ifstream &in);
    void readOperAmp(std::ifstream &in);
    void readTransformer(std::ifstream &in);
    void readPOAmp(std::ifstream &in);
    void readPerfTrans(std::ifstream &in);


    /*std::vector<std::array<int, 2>> nodeR; // - +
    std::vector<std::array<int, 2>> nodeC; // - +
    std::vector<std::array<int, 2>> nodeL; // - +
    std::vector<std::array<int, 4>> nodeITUN; // - + - +
    std::vector<std::array<int, 4>> nodeINUN; // - + - +
    std::vector<std::array<int, 4>> nodeITUT; // - + - +
    std::vector<std::array<int, 4>> nodeINUT; // - + - +
    std::vector<std::array<int, 3>> nodeBPTrans;
    std::vector<std::array<int, 3>> nodeUPTrans;
    std::vector<std::array<int, 4>> nodeOperAmp;
    std::vector<std::array<int, 4>> nodeTransformer;
    std::vector<std::array<int, 4>> nodePOAmp;
    std::vector<std::array<int, 3>> nodePerfTrans;
    std::vector<double> valueR;
    std::vector<double> valueC;
    std::vector<double> valueL;
    std::vector<double> valueITUN;
    std::vector<double> valueINUN;
    std::vector<double> valueITUT;
    std::vector<double> valueINUT;
    std::vector<std::array<double, 6>> valueBPTrans;
    std::vector<std::array<double, 5>> valueUPTrans;
    std::vector<std::array<double, 4>> valueOperAmp;
    std::vector<std::array<double, 4>> valueTranformer;
    std::vector<std::array<double, 4>> valuePOAmp;
    std::vector<std::array<double, 5>> valuePerfTrans;*/
    MatrixT<int> nodeR; // - +
    MatrixT<int> nodeC; // - +
    MatrixT<int> nodeL; // - +
    MatrixT<int> nodeITUN; // - + - +
    MatrixT<int> nodeINUN; // - + - +
    MatrixT<int> nodeITUT; // - + - +
    MatrixT<int> nodeINUT; // - + - +
    MatrixT<int> nodeBPTrans;
    MatrixT<int> nodeUPTrans;
    MatrixT<int> nodeOperAmp;
    MatrixT<int> nodeTransformer;
    MatrixT<int> nodePOAmp;
    MatrixT<int> nodePerfTrans;
    MatrixT<double> valueR;
    MatrixT<double> valueC;
    MatrixT<double> valueL;
    MatrixT<double> valueITUN;
    MatrixT<double> valueINUN;
    MatrixT<double> valueITUT;
    MatrixT<double> valueINUT;
    MatrixT<double> valueBPTrans;
    MatrixT<double> valueUPTrans;
    MatrixT<double> valueOperAmp;
    MatrixT<double> valueTranformer;
    MatrixT<double> valuePOAmp;
    MatrixT<double> valuePerfTrans;
    size_t maxnodes;

};

#endif // ELEMENTSPARAMS_H

