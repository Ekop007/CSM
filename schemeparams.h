#ifndef SCHEMEPARAMS_H
#define SCHEMEPARAMS_H

#include <cstdint>

struct SchemeParams
{
    SchemeParams();
    SchemeParams(std::size_t nc, std::size_t res, std::size_t cap, std::size_t ind, std::size_t itun,
                 std::size_t inun, std::size_t itut, std::size_t inut, std::size_t bpt, std::size_t upt,
                 std::size_t oa, std::size_t tran, std::size_t poa, std::size_t pt);
    SchemeParams(SchemeParams const &sp);
    SchemeParams(SchemeParams &&sp) noexcept;
    void operator=(SchemeParams &sp);
    void operator=(SchemeParams sp);
    void Swap(SchemeParams sp);


    std::size_t node_count;
    std::size_t resistors;
    std::size_t capasitors;
    std::size_t inductances;
    std::size_t itun;
    std::size_t inun;
    std::size_t itut;
    std::size_t inut;
    std::size_t b_p_transistors;
    std::size_t u_p_transistors;
    std::size_t oper_ampfilers;
    std::size_t transformers;
    std::size_t p_o_ampfilers;
    std::size_t perf_transistors;
};

#endif // SCHEMEPARAMS_H
