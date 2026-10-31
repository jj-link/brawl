#include <types.h>
#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define RG PASTE(r, egister)

u32 PPCMfhid2(void)
{
    RG u32 value;
    BLOCK { mfspr value, 0x398 }
    return value;
}
