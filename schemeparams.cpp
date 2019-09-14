#include <algorithm>
#include "schemeparams.h"

SchemeParams::SchemeParams(): node_count(0), resistors(0), capasitors(0), inductions(0),
                           itun(0), inun(0), itut(0), inut(0), b_p_transistors(0),
                           u_p_transistors(0), oper_ampfilers(0), transformers(0),
                           p_o_ampfilers(0), perf_transistors(0)
{

}

SchemeParams::SchemeParams(int nc, int res, int cap, int ind, int itun,
                           int inun, int itut, int inut, int bpt, int upt,
                           int oa, int tran, int poa, int pt) : node_count(nc),
                           resistors(res), capasitors(cap), inductions(ind), itun(itun),
                           inun(inun), itut(itut), inut(inut), b_p_transistors(bpt),
                           u_p_transistors(upt), oper_ampfilers(oa), transformers(tran),
                           p_o_ampfilers(poa), perf_transistors(pt)
{

}

SchemeParams::SchemeParams(SchemeParams const &sp) : node_count(sp.node_count), resistors(sp.resistors),
                           capasitors(sp.capasitors), inductions(sp.inductions), itun(sp.itun),
                           inun(sp.inun), itut(sp.itut), inut(sp.inut), b_p_transistors(sp.b_p_transistors),
                           u_p_transistors(sp.u_p_transistors), oper_ampfilers(sp.oper_ampfilers),
                           transformers(sp.transformers), p_o_ampfilers(sp.p_o_ampfilers),
                           perf_transistors(sp.perf_transistors)
{

}

SchemeParams::SchemeParams(SchemeParams &&sp) noexcept : node_count(sp.node_count), resistors(sp.resistors),
                           capasitors(sp.capasitors), inductions(sp.inductions), itun(sp.itun),
                           inun(sp.inun), itut(sp.itut), inut(sp.inut), b_p_transistors(sp.b_p_transistors),
                           u_p_transistors(sp.u_p_transistors), oper_ampfilers(sp.oper_ampfilers),
                           transformers(sp.transformers), p_o_ampfilers(sp.p_o_ampfilers),
                           perf_transistors(sp.perf_transistors)
{
    sp.node_count = 0;
    sp.resistors = 0;
    sp.capasitors = 0;
    sp.inductions = 0;
    sp.itun = 0;
    sp.inun = 0;
    sp.itut = 0;
    sp.inut = 0;
    sp.b_p_transistors = 0;
    sp.u_p_transistors = 0;
    sp.transformers = 0;
    sp.p_o_ampfilers = 0;
    sp.perf_transistors = 0;
}

void SchemeParams::operator=(SchemeParams &sp)
{
    SchemeParams tmp(sp);
    Swap (tmp);
}

void SchemeParams::operator=(SchemeParams sp)
{
    Swap(sp);
}

void SchemeParams::Swap(SchemeParams sp)
{
    node_count = std::move(sp.node_count);
    resistors = std::move(sp.resistors);
    capasitors = std::move(sp.capasitors);
    inductions = std::move(sp.inductions);
    itun = std::move(sp.itun);
    inun = std::move(sp.inun);
    itut = std::move(sp.itut);
    inut = std::move(sp.inut);
    b_p_transistors = std::move(sp.b_p_transistors);
    u_p_transistors = std::move(sp.u_p_transistors);
    transformers = std::move(sp.transformers);
    p_o_ampfilers = std::move(sp.p_o_ampfilers);
    perf_transistors = std::move(sp.perf_transistors);
    sp.node_count = 0;
    sp.resistors = 0;
    sp.capasitors = 0;
    sp.inductions = 0;
    sp.itun = 0;
    sp.inun = 0;
    sp.itut = 0;
    sp.inut = 0;
    sp.b_p_transistors = 0;
    sp.u_p_transistors = 0;
    sp.transformers = 0;
    sp.p_o_ampfilers = 0;
    sp.perf_transistors = 0;

}
