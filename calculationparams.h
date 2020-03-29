#ifndef CALCULATIONPARAMS_H
#define CALCULATIONPARAMS_H

#include <array>
#include <fstream>

struct CalculationParams
{
public:
    CalculationParams();

    void write(std::ofstream &out);
    void read(std::ifstream &in);


    int flag_frequency_response;
    std::array<double, 3> frequency;
    std::array<int, 2> in_nodes; // - +
    std::array<int, 2> out_nodes; // - +
};

#endif // CALCULATIONPARAMS_H
