#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A45CC(void* p)
{
    u32 x = *(u32*)((u8*)p + 8);
    return (s32)(((x >> 11) & 0x7FF) << 21) >> 22;
}
