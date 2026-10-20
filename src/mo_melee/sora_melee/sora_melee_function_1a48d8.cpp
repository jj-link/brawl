#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A48D8(const u32* p)
{
    return ((s32)((p[2] << 10) & 0xFFE00000)) >> 22;
}
