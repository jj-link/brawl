#include <types.h>
#pragma force_active on

struct Fld {
    u32 pad[2];
    u32 a : 7;
    u32 b : 7;
    u32 c : 18;
};

extern "C" void fn_27_1D026C(Fld* p, u32 v)
{
    p->b = v;
}
