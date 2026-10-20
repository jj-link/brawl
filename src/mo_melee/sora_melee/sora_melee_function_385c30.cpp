#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_385C30(u32 *p);

s32 fn_27_385C30(u32 *p)
{
    u32 x = p[2];
    return (s32)((x << 20) & 0xFFE00000) >> 22;
}
