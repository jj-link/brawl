#include <types.h>

#pragma force_active on

asm u32 PPCMfmsr(void) {
    nofralloc
    mfmsr r3
    blr
}
