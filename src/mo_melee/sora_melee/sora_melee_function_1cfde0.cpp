#include <types.h>
#pragma force_active on

struct Bits {
    u32 a : 10;
    u32 f : 5;
    u32 b : 17;
};

struct Obj {
    u32 pad[2];
    Bits bits;
};

extern "C" void fn_27_1CFDE0(Obj *p, u32 v)
{
    p->bits.f = v;
}
