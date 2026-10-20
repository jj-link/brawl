#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_122318(void* p)
{
    u32 w = ((u32*)p)[2];
    return (s32)((w << 8) & 0xF8000000) >> 28;
}
