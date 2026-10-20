#include <types.h>
#pragma force_active on

struct Fld {
    u32 a;
    u32 b;
    u32 hi : 4;
    u32 f : 4;
    u32 rest : 24;
};

extern "C" void fn_27_1D01B4(Fld *p, u32 v)
{
    p->f = v;
}
