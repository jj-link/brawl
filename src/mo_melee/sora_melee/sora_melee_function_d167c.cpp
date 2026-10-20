#include <types.h>
#pragma force_active on

struct Bf {
    u32 a : 8;
    u32 b : 8;
    u32 c : 16;
};

extern "C" void fn_27_D167C(u32 *p, u32 v)
{
    ((Bf *)(p + 2))->b = v;
}
