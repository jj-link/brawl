#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_D09AC(void* p);
}

extern "C" s32 fn_27_D09AC(void* p)
{
    u32 x = *(u32*)((u8*)p + 8);
    u32 r = (x << 7) | (x >> 25);
    return ((s32)(r & 0xFF000000)) >> 25;
}
