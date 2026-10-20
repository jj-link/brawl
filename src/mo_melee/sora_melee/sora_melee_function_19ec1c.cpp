#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_19EC1C(u32* p)
{
    u32 v = (p[2] << 4) & 0xE0000000;
    return (s32)v >> 30;
}
