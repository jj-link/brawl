#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_1A4630(u8* p)
{
    u32 x = *(u32*)(p + 8);
    u32 r = (x >> 12) | (x << 20);
    r &= 0xFFE00000;
    return (s32)r >> 22;
}
}
