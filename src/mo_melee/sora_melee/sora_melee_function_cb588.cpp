#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_CB588(void* p)
{
    u32 x = *(u32*)((u8*)p + 8);
    u32 y = ((x >> 25) & 7) << 29;
    return (s32)y >> 30;
}
