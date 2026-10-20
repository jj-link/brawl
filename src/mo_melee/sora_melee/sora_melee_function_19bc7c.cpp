#include <types.h>
#pragma force_active on

struct fn_27_19BC7C_S {
    u32 pad[2];
    u32 bits;
};

extern "C" s32 fn_27_19BC7C(fn_27_19BC7C_S *p)
{
    u32 w = p->bits;
    return (s32)(((w << 10) | (w >> 22)) & 0xFC000000) >> 27;
}
