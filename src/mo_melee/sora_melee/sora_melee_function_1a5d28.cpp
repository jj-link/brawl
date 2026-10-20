#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A5D28(const void *arg)
{
    return (s32)((*(const u32 *)((const u8 *)arg + 8) << 10) & 0xFFE00000u) >> 22;
}
