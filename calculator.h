#ifndef CALCULATOR_H
#define CALCULATOR_H
#define _USE_MATH_DEFINES
#include <memory>
#include "matrix.h"
#include "complex.h"
#include "schemeparams.h"
#include "elementsparams.h"
#include "calculationparams.h"

class Calculator
{
public:
    Calculator();

    void calculateMatrix();
    void run();
    void run1();
    MatrixT<complex> &getW() { return W; }
    void form_D(const complex &s);
    void form_IU(const complex &s); // источник * управляемый *
    void form_UU(const complex &s); // источник * управляемый *
    void form_II(const complex &s); // источник * управляемый *
    void form_UI(const complex &s); // источник * управляемый *
    void form_S();
    void form_OU(const complex &s);
    void form_BT(const complex &s);
    void form_Tr(const complex &s);
    void form_PerfTr();

    void form1_D();
    void form1_IU(); // источник * управляемы *
    void form1_UU(); // источник * управляемы *
    void form1_II(); // источник * управляемы *
    void form1_UI(); // источник * управляемы *
    void form1_S();
    void setSizeW1();
    void setSchemeParams(std::shared_ptr<SchemeParams> &ptr);
    void setElemetsParams(std::shared_ptr<ElementsParams> &ptr);
    void setCalculationParams(std::shared_ptr<CalculationParams> &ptr);
    std::vector<double> &getKUM() { return kum; }
    std::vector<double> &getKUA() { return kua; }
    std::vector<double> &getRIM() { return rim; }
    std::vector<double> &getRIA() { return ria; }
    std::vector<double> &getROM() { return rom; }
    std::vector<double> &getROA() { return roa; }
    std::vector<double> &getF() { return f_; }

private:
    void setSizeW();
    void gauss_C();
    void st();
    void sf1(size_t step);
    void sf2(size_t step);

    std::shared_ptr<SchemeParams> scheme_params_ptr;
    std::shared_ptr<ElementsParams> elements_params_ptr;
    std::shared_ptr<CalculationParams> calculation_params_ptr;
    MatrixT<complex> W;
    MatrixT<double> A;
    MatrixT<double> B;
    size_t n_;
    std::vector<double> f_;
    std::vector<double> kum;
    std::vector<double> kua;
    std::vector<double> rim;
    std::vector<double> ria;
    std::vector<double> rom;
    std::vector<double> roa;
};

#endif // CALCULATOR_H
