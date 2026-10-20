#include <types.h>
#pragma force_active on

extern "C" {
struct fn27Bits {
    u32 pad[2];
    u32 a : 7;
    u32 f : 7;
    u32 b : 18;
};

void fn_27_D0E84(fn27Bits* p, u32 v)
{
    p->f = v;
}
}
