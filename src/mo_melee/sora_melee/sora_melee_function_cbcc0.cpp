#include <types.h>
#pragma force_active on

struct Bits {
    u32 hi : 5;
    u32 rest : 27;
};

extern "C" void fn_27_CBCC0(Bits *p, u32 v)
{
    p[2].hi = v;
}
