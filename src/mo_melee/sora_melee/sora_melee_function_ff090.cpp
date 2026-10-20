#include <types.h>
#pragma force_active on

struct Bits {
    u32 hi : 2;
    u32 rest : 30;
};

extern "C" void fn_27_FF090(Bits *p, u32 v)
{
    p[2].hi = v;
}
