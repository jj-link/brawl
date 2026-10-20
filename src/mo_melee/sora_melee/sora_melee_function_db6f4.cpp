#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_DB6F4(void* p)
{
    u32 x = ((u32*)p)[2];
    s32 v = (x >> 22) & 0xF;
    return (s32)(v << 28) >> 29;
}
