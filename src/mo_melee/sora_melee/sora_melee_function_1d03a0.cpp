#include <types.h>
#pragma force_active on

struct Obj {
    u32 pad[2];
    u32 a : 14;
    u32 bits : 7;
    u32 b : 11;
};

extern "C" void fn_27_1D03A0(Obj *p, u32 v)
{
    p->bits = v;
}
