#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_CF1C4(void *p)
{
    u32 w = *(u32 *)((u8 *)p + 8);
    u32 t = (w >> 19) & 0x7F;
    return ((s32)(t << 25)) >> 26;
}
