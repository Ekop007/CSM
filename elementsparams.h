#ifndef ELEMENTSPARAMS_H
#define ELEMENTSPARAMS_H
#include <vector>

class ElementsParams
{
public:
    ElementsParams();
    void Init(size_t rc, size_t cc, size_t lc);

    std::vector<std::pair<int, int>> in_r;
    std::vector<std::pair<int, int>> in_l;
    std::vector<std::pair<int, int>> in_c;
    std::vector<double> z_r;
    std::vector<double> z_c;
    std::vector<double> z_l;
};

#endif // ELEMENTSPARAMS_H
