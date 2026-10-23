#include <revolution/BASE.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

#define PASTE(a, b) a##b
#define ASM_KEYWORD PASTE(__as, m)

ASM_KEYWORD BOOL OSRestoreInterrupts(BOOL enable) {
    // clang-format off
    nofralloc

    cmpwi r3, 0
    mfmsr r4
    beq disable
    ori r5, r4, 0x8000
    b set_msr
disable:
    rlwinm r5, r4, 0, 17, 15
set_msr:
    mtmsr r5
    extrwi r3, r4, 1, 16
    blr
    // clang-format on
}
