#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A6098(void* p)
{
    u32 v = ((u32*)p)[2];
    u32 r = (v << 20) | (v >> 12);
    return (s32)(r & 0xFFE00000) >> 22;
}
