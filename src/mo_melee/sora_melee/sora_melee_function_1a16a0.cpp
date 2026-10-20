#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A16A0(void* p)
{
    u32 v = *(u32*)((u8*)p + 8);
    v = (v << 4) & 0xE0000000;
    return (s32)v >> 30;
}
