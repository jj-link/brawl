#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A5364(u32* p)
{
    u32 v = (p[2] << 12) & 0xFE000000;
    return (s32)v >> 26;
}
