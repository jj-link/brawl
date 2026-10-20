#include <types.h>
#pragma force_active on

struct Bits {
    u32 hi : 3;
    u32 rest : 29;
};

struct Holder {
    u32 pad[2];
    Bits b;
};

extern "C" void fn_27_295C30(Holder *p, u32 val)
{
    p->b.hi = val;
}
