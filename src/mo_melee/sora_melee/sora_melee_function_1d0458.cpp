#include <types.h>
#pragma force_active on

struct Field8 {
    u32 a : 8;
    u32 f : 4;
    u32 b : 20;
};

struct Wrap {
    u32 pad0;
    u32 pad1;
    Field8 fld;
};

extern "C" void fn_27_1D0458(Wrap *p, u32 val)
{
    p->fld.f = val;
}
