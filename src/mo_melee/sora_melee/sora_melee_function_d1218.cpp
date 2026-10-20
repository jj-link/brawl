#include <types.h>
#pragma force_active on

struct Fn27Bits {
    u32 hi : 16;
    u32 mid : 8;
    u32 lo : 8;
};

extern "C" void fn_27_D1218(u8* p, u32 v)
{
    Fn27Bits* s = (Fn27Bits*)(p + 8);
    s->mid = v;
}
