#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_1B21F8(void* p)
{
    u32 v = ((u32*)p)[2];
    return (s32)((v << 6) & 0xF0000000) >> 29;
}
}
