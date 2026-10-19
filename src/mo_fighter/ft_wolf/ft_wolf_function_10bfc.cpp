#include <stddef.h>
#pragma force_active on

extern "C" void fn_125_10BFC(long r3, long r4)
{
    long *p = (long *)r3;
    p[4] = r4;
    p[3] = r4;
    p[2] = r4;
}
