#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_198090(s32 *p)
{
    u32 x = (u32)p[2];
    u32 v = ((x << 3) | (x >> 29)) & 0xF0000000;
    return (s32)v >> 29;
}
}
