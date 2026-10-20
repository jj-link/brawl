#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_CA734(u32 *p)
{
    u32 x = p[2];
    return (s32)((x & 0x3F0000) << 10) >> 27;
}
