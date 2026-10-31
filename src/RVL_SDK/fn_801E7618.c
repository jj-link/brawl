#include <revolution/BASE.h>
#pragma force_active on

#define PASTE(a, b) a##b
#define ASM_KEYWORD PASTE(__as, m)

extern void fn_801E75D0(void);

ASM_KEYWORD void __DBExceptionDestination(void) {
    // clang-format off
    nofralloc

    mfmsr r3
    ori r3, r3, 0x30
    mtmsr r3
    b fn_801E75D0
    // clang-format on
}
