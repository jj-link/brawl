#include <types.h>
#pragma force_active on

extern "C" void fn_115_17334(void *arg, u32 val)
{
    u32 *p = (u32 *)arg;
    p[4] = val;
    p[3] = val;
    p[2] = val;
}
