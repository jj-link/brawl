#include <types.h>
#pragma force_active on

struct Bits {
    u32 hi : 9;
    u32 lo : 23;
};

struct Outer {
    u32 a;
    u32 b;
    Bits c;
};

extern "C" void fn_27_543B4(Outer* p, u32 v)
{
    p->c.hi = v;
}
