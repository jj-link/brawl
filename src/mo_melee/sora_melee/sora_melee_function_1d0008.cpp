#include <types.h>
#pragma force_active on

struct W {
    u32 hi : 8;
    u32 f : 4;
    u32 lo : 20;
};

extern "C" void fn_27_1D0008(void* p, u32 v)
{
    W* w = (W*)((u8*)p + 8);
    w->f = v;
}
