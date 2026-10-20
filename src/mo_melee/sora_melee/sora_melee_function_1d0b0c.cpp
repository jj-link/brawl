#include <types.h>
#pragma force_active on

struct Fn27Bits {
    u32 pad[2];
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

extern "C" void fn_27_1D0B0C(Fn27Bits* p, u32 v)
{
    p->b = v;
}
