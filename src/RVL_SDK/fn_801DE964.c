#include <types.h>

#pragma force_active on

asm void fn_801DE964(u32 addr) {
    nofralloc
    clrlwi r3, r3, 2
    mtsrr0 r3
    mfmsr r3
    rlwinm r3, r3, 0, 28, 25
    mtsrr1 r3
    rfi
}
