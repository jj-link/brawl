#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_2911AC(u32 *p)
{
    return ((s32)((p[2] << 6) & 0xFE000000)) >> 26;
}
