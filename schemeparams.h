#ifndef SCHEMEPARAMS_H
#define SCHEMEPARAMS_H



struct SchemeParams
{
    SchemeParams();
    SchemeParams(int nc, int res, int cap, int ind, int itun,
                 int inun, int itut, int inut, int bpt, int upt,
                 int oa, int tran, int poa, int pt);
    SchemeParams(SchemeParams const &sp);
    SchemeParams(SchemeParams &&sp) noexcept;
    void operator=(SchemeParams &sp);
    void operator=(SchemeParams sp);
    void Swap(SchemeParams sp);


    int node_count;
    int resistors;
    int capasitors;
    int inductances;
    int itun;
    int inun;
    int itut;
    int inut;
    int b_p_transistors;
    int u_p_transistors;
    int oper_ampfilers;
    int transformers;
    int p_o_ampfilers;
    int perf_transistors;
};

#endif // SCHEMEPARAMS_H
