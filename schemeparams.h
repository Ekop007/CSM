#ifndef SCHEMEPARAMS_H
#define SCHEMEPARAMS_H

#include <cstdint>
#include <fstream>

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
    void swap(SchemeParams sp);
    void allCount();
    void write(std::ofstream &out);
    void read(std::ifstream &in);

    std::size_t node_count;
    std::size_t resistors;
    std::size_t capasitors;
    std::size_t inductances;
    std::size_t itun; // источник (Т - тока, н - напряж), управляемый (Т Н)
    std::size_t inun;
    std::size_t itut;
    std::size_t inut;
    std::size_t b_p_transistors;
    std::size_t u_p_transistors;
    std::size_t oper_amplifiers;
    std::size_t transformers; // 4 + коэф транс
    std::size_t p_o_amplifiers;
    std::size_t perf_transistors;
    std::size_t all_count;
};

#endif // SCHEMEPARAMS_H
