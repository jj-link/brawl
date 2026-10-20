#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_19836C(u32 *p)
{
    return (s32)((p[2] << 8) & 0xF8000000) >> 28;
}
}
