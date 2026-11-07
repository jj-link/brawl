#include <types.h>

#pragma force_active on

asm u32 PPCMfhid0(void) {
    // clang-format off
    nofralloc
    mfhid0 r3
    blr
    // clang-format on
}
