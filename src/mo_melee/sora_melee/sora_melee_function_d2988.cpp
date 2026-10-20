#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_D2988(void* p)
{
    u32 x = *(u32*)((u8*)p + 8);
    u32 r = (x << 3) | (x >> 29);
    return (s32)(r & 0xF0000000) >> 29;
}
