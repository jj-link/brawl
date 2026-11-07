#include <types.h>

#pragma force_active on

asm void fn_801D7FCC(u32 arg0) {
    nofralloc
    lis r4, 0x8000
    stw r3, 0xd4(r4)
    clrlwi r5, r3, 2
    stw r5, 0xc0(r4)
    lwz r5, 0xd8(r4)
    cmpw r5, r3
    bne not_current
    lwz r6, 0x19c(r3)
    ori r6, r6, 0x2000
    stw r6, 0x19c(r3)
    mfmsr r6
    ori r6, r6, 0x2
    mtmsr r6
    blr
not_current:
    lwz r6, 0x19c(r3)
    rlwinm r6, r6, 0, 19, 17
    stw r6, 0x19c(r3)
    mfmsr r6
    rlwinm r6, r6, 0, 19, 17
    ori r6, r6, 0x2
    mtmsr r6
    isync
    blr
}
