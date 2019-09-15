#include "elementsparams.h"

ElementsParams::ElementsParams()
{

}

void ElementsParams::Init(size_t rc, size_t cc, size_t lc)
{
    in_r.resize(rc);
    in_c.resize(cc);
    in_l.resize(lc);
    z_r.resize(rc);
    z_c.resize(cc);
    z_l.resize(lc);
}
