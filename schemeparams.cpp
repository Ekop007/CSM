#include <algorithm>
#include "schemeparams.h"

SchemeParams::SchemeParams(): node_count(0), resistors(0), capasitors(0), inductances(0),
                           itun(0), inun(0), itut(0), inut(0), b_p_transistors(0),
                           u_p_transistors(0), oper_amplifiers(0), transformers(0),
                           p_o_amplifiers(0), perf_transistors(0)
{

}

SchemeParams::SchemeParams(std::size_t nc, std::size_t res, std::size_t cap, std::size_t ind, std::size_t itun,
                           std::size_t inun, std::size_t itut, std::size_t inut, std::size_t bpt, std::size_t upt,
                           std::size_t oa, std::size_t tran, std::size_t poa, std::size_t pt, std::size_t ptr) : node_count(nc),
                           resistors(res), capasitors(cap), inductances(ind), itun(itun),
                           inun(inun), itut(itut), inut(inut), b_p_transistors(bpt),
                           u_p_transistors(upt), oper_amplifiers(oa), transformers(tran),
                           p_o_amplifiers(poa), perf_transistors(pt), perfect_transformer(ptr)
{

}

SchemeParams::SchemeParams(SchemeParams const &sp) : node_count(sp.node_count), resistors(sp.resistors),
                           capasitors(sp.capasitors), inductances(sp.inductances), itun(sp.itun),
                           inun(sp.inun), itut(sp.itut), inut(sp.inut), b_p_transistors(sp.b_p_transistors),
                           u_p_transistors(sp.u_p_transistors), oper_amplifiers(sp.oper_amplifiers),
                           transformers(sp.transformers), p_o_amplifiers(sp.p_o_amplifiers),
                           perf_transistors(sp.perf_transistors), perfect_transformer(sp.perfect_transformer)
{

}

SchemeParams::SchemeParams(SchemeParams &&sp) noexcept : node_count(std::move(sp.node_count)), resistors(std::move(sp.resistors)),
                           capasitors(std::move(sp.capasitors)), inductances(std::move(sp.inductances)), itun(std::move(sp.itun)),
                           inun(std::move(sp.inun)), itut(std::move(sp.itut)), inut(std::move(sp.inut)),
                           b_p_transistors(std::move(sp.b_p_transistors)), u_p_transistors(std::move(sp.u_p_transistors)),
                           oper_amplifiers(std::move(sp.oper_amplifiers)), transformers(std::move(sp.transformers)),
                           p_o_amplifiers(std::move(sp.p_o_amplifiers)), perf_transistors(std::move(sp.perf_transistors)),
                           perfect_transformer(std::move(sp.perfect_transformer))
{
    sp.node_count = 0;
    sp.resistors = 0;
    sp.capasitors = 0;
    sp.inductances = 0;
    sp.itun = 0;
    sp.inun = 0;
    sp.itut = 0;
    sp.inut = 0;
    sp.b_p_transistors = 0;
    sp.u_p_transistors = 0;
    sp.transformers = 0;
    sp.p_o_amplifiers = 0;
    sp.perf_transistors = 0;
    sp.perfect_transformer = 0;
}

void SchemeParams::operator=(SchemeParams &sp)
{
    SchemeParams tmp(sp);
    swap (tmp);
}

void SchemeParams::operator=(SchemeParams sp)
{
    swap(sp);
}

void SchemeParams::swap(SchemeParams sp)
{
    node_count = std::move(sp.node_count);
    resistors = std::move(sp.resistors);
    capasitors = std::move(sp.capasitors);
    inductances = std::move(sp.inductances);
    itun = std::move(sp.itun);
    inun = std::move(sp.inun);
    itut = std::move(sp.itut);
    inut = std::move(sp.inut);
    b_p_transistors = std::move(sp.b_p_transistors);
    u_p_transistors = std::move(sp.u_p_transistors);
    transformers = std::move(sp.transformers);
    p_o_amplifiers = std::move(sp.p_o_amplifiers);
    perf_transistors = std::move(sp.perf_transistors);
    perfect_transformer = std::move(sp.perfect_transformer);
    sp.node_count = 0;
    sp.resistors = 0;
    sp.capasitors = 0;
    sp.inductances = 0;
    sp.itun = 0;
    sp.inun = 0;
    sp.itut = 0;
    sp.inut = 0;
    sp.b_p_transistors = 0;
    sp.u_p_transistors = 0;
    sp.transformers = 0;
    sp.p_o_amplifiers = 0;
    sp.perf_transistors = 0;
    sp.perfect_transformer = 0;
}

void SchemeParams::allCount()
{
    all_count = resistors + capasitors + inductances + itun + inun
            + itut + inut + b_p_transistors + u_p_transistors
            + transformers + p_o_amplifiers + perf_transistors + perfect_transformer;
}

void SchemeParams::write(std::ofstream &out)
{
    out << node_count << " " << resistors << " " << capasitors << " " << inductances << " " << itun << " " << inun << " " << itut << " "
        << inut << " " << b_p_transistors << " " << u_p_transistors << " " << transformers << " " << p_o_amplifiers << " "
        << perf_transistors << " " << perfect_transformer << std::endl;
}

void SchemeParams::read(std::ifstream &in)
{
    in >> node_count >> resistors >> capasitors >> inductances >> itun >> inun >> itut >> inut >> b_p_transistors
            >> u_p_transistors >> transformers >> p_o_amplifiers >> perf_transistors >> perfect_transformer;
}
