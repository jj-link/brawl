#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_CE238(void *self)
{
    u32 value = *(u32 *)((char *)self + 8);
    return (s32)((value << 16) & 0xFF800000) >> 24;
}
