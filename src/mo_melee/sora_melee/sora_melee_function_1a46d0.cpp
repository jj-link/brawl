#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A46D0(void* p)
{
    return (s32)((*(u32*)((u8*)p + 8) << 10) & 0xFFE00000) >> 22;
}
