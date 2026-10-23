#include <revolution/BASE.h>

#pragma force_active on

#define PPCASM a##sm

PPCASM BOOL fn_801DCF24(void) {
    // clang-format off
    nofralloc

    mfmsr r3
    ori r4, r3, MSR_EE
    mtmsr r4

    rlwinm r3, r3, 17, 31, 31
    blr
    // clang-format on
}
