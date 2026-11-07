#include <types.h>
#pragma force_active on

asm void PPCMtmsr(u32 val) {
    nofralloc
    mtmsr r3
    blr
}
