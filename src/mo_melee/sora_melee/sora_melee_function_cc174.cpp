#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_CC174(u32 *p)
{
    u32 v = (p[2] >> 27) & 7;
    return (s32)(v << 29) >> 30;
}
