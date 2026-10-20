#include <types.h>
#pragma force_active on

extern "C" {
struct fn_27_1A72A0_S {
    u32 pad[2];
    u32 a : 4;
    u32 f : 4;
    u32 b : 24;
};

void fn_27_1A72A0(fn_27_1A72A0_S* p, u32 v)
{
    p->f = v;
}
}
