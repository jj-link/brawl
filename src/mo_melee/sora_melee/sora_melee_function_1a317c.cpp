#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A317C(const void *p)
{
    return (s32)((*(const u32 *)((const u8 *)p + 8) << 6) & 0xFE000000u) >> 26;
}
