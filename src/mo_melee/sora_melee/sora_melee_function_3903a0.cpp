#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_3903A0(void* p)
{
    u32 x = ((u32*)p)[2];
    return (s32)((x << 4) & 0xF8000000) >> 28;
}
