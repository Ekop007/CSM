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

    void run();
    MatrixT<complex> &getW() { return W; }
    void form_D(const complex &s);
    void form_IU(); // источник * управляемы *
    void form_UU(); // источник * управляемы *
    void form_II(); // источник * управляемы *
    void form_UI(); // источник * управляемы *
    void form_S();
    void setSizeW();
    void setSchemeParams(std::shared_ptr<SchemeParams> &ptr);
    void setElemetsParams(std::shared_ptr<ElementsParams> &ptr);
    void setCalculationParams(std::shared_ptr<CalculationParams> &ptr);
    std::vector<double> &getKUM() { return kum; }
    std::vector<double> &getKUA() { return kua; }
    std::vector<double> &getRIM() { return rim; }
    std::vector<double> &getRIA() { return ria; }
    std::vector<double> &getROM() { return rom; }
    std::vector<double> &getROA() { return roa; }

private:
    void gauss_C();
    void st();
    void sf1(size_t step);
    void sf2(size_t step);

    std::shared_ptr<SchemeParams> scheme_params_ptr;
    std::shared_ptr<ElementsParams> elements_params_ptr;
    std::shared_ptr<CalculationParams> calculation_params_ptr;
    MatrixT<complex> W;
    std::vector<double> kum;
    std::vector<double> kua;
    std::vector<double> rim;
    std::vector<double> ria;
    std::vector<double> rom;
    std::vector<double> roa;
};

#endif // CALCULATOR_H
