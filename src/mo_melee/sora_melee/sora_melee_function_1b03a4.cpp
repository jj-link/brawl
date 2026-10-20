#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1B03A4(void* p, s32 idx)
{
    s32 v = *(s32*)((u8*)p + 8);
    s32 r = (v >> 27) + idx;
    if (r >= 12) {
        r -= 12;
    }
    return (u8*)p + r * 0x60 + 0xc;
}
