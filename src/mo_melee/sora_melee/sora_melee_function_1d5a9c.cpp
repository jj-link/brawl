#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1D5A9C(void* p)
{
    u32 v = ((u32*)p)[2];
    u32 r = (v << 5) | (v >> 27);
    return (s32)(r & 0xFC000000) >> 27;
}
