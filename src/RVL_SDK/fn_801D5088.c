#include <types.h>

#pragma force_active on

asm u32 PPCMfl2cr(void) {
    nofralloc
    mfspr r3, 0x3F9
    blr
}
