#include <types.h>
#pragma force_active on

struct Bits {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

struct Outer {
    u32 pad[2];
    Bits bits;
};

extern "C" void fn_27_19B9E0(Outer* p, u32 v)
{
    p->bits.b = v;
}
