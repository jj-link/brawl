#include <types.h>
#pragma force_active on

extern "C" {
int fn_27_1D0AFC(const u32* p)
{
    u32 x = p[2];
    return (s32)(((x << 4) | (x >> 28)) & 0xF8000000) >> 28;
}
}
