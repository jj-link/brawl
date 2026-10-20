#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_CEA30(u32 *p)
{
    u32 x = p[2];
    return (s32)(((x >> 13) & 0x7F) << 25) >> 26;
}
}
