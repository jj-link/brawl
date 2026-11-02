#define PP_CAT_I(a, b) a##b
#define PP_CAT(a, b) PP_CAT_I(a, b)
#define ASSEMBLY PP_CAT(as, m)

#include <revolution/OS/OSContext.h>

#pragma force_active on

ASSEMBLY int fn_801D8034(void) {
    // clang-format off
    nofralloc

    stmw r13, 0x34(r3)

    mfspr r0, GQR1
    stw r0, 0x1a8(r3)
    mfspr r0, GQR2
    stw r0, 0x1ac(r3)
    mfspr r0, GQR3
    stw r0, 0x1b0(r3)
    mfspr r0, GQR4
    stw r0, 0x1b4(r3)
    mfspr r0, GQR5
    stw r0, 0x1b8(r3)
    mfspr r0, GQR6
    stw r0, 0x1bc(r3)
    mfspr r0, GQR7
    stw r0, 0x1c0(r3)

    mfcr r0
    stw r0, 0x80(r3)

    mflr r0
    stw r0, 0x84(r3)
    stw r0, 0x198(r3)

    mfmsr r0
    stw r0, 0x19c(r3)

    mfctr r0
    stw r0, 0x88(r3)

    mfxer r0
    stw r0, 0x8c(r3)

    stw r1, 0x4(r3)
    stw r2, 0x8(r3)

    li r0, 1
    stw r0, 0xc(r3)

    li r3, 0
    blr
    // clang-format on
}
