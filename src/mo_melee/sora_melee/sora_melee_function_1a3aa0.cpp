#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A3AA0(void* p)
{
    u32 v = *(u32*)((u8*)p + 8);
    return (s32)((v << 10) & 0xFFE00000) >> 22;
}
