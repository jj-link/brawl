#include <types.h>
#pragma force_active on

struct Bits {
    u32 a : 8;
    u32 b : 24;
};

struct Holder {
    u32 pad[2];
    Bits bits;
};

extern "C" void fn_27_D1194(Holder *p, u32 v)
{
    p->bits.a = v;
}
