#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_19EA20(void* p)
{
    u32 x = *(u32*)((u8*)p + 8);
    u32 t = (x << 6) & 0xFE000000;
    return (s32)t >> 26;
}
