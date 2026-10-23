#include <revolution/BASE.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

#define PASTE(a, b) a##b
#define ASM_KEYWORD PASTE(__as, m)

ASM_KEYWORD BOOL OSDisableInterrupts(void) {
    // clang-format off
    nofralloc

    mfmsr r3
    rlwinm r4, r3, 0, 17, 15
    mtmsr r4
    rlwinm r3, r3, 17, 31, 31
    blr
    // clang-format on
}
