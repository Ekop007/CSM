#include "calculationparams.h"

CalculationParams::CalculationParams() : flag_frequency_response(3), frequency({0, 0, 0}), in_nodes({0, 0}), out_nodes({0, 0})
{

}

void CalculationParams::write(std::ofstream &out)
{
    out << flag_frequency_response << " " << frequency[0] << " " << frequency[1] << " " << frequency[2]
        << " " << in_nodes[0] << " " << in_nodes[1] << " " << out_nodes[0] << " " << out_nodes[1] << std::endl;
}

void CalculationParams::read(std::ifstream &in)
{
    in >> flag_frequency_response >> frequency[0] >> frequency[1] >> frequency[2]
       >> in_nodes[0] >> in_nodes[1] >> out_nodes[0] >> out_nodes[1];
}
