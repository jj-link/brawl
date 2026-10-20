#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_19A67C(u32 *p)
{
    u32 v = p[2];
    return (s32)(((v << 6) | (v >> 26)) & 0xF0000000) >> 29;
}
