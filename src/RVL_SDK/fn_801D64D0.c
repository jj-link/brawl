#include <revolution/OS/OSContext.h>
#pragma force_active on

#define PP_CAT_I(a, b) a##b
#define PP_CAT(a, b) PP_CAT_I(a, b)
#define ASSEMBLY PP_CAT(as, m)

extern void fn_801D8A44(u8 error, OSContext* ctx, u32 dsisr, u32 dar);

ASSEMBLY void fn_801D64D0(u8 error) {
    // clang-format off
    nofralloc

    stw r0, 0(r4)
    stw r1, 4(r4)
    stw r2, 8(r4)
    stmw r6, 0x18(r4)

    mfspr r0, GQR1
    stw r0, 0x1A8(r4)
    mfspr r0, GQR2
    stw r0, 0x1AC(r4)
    mfspr r0, GQR3
    stw r0, 0x1B0(r4)
    mfspr r0, GQR4
    stw r0, 0x1B4(r4)
    mfspr r0, GQR5
    stw r0, 0x1B8(r4)
    mfspr r0, GQR6
    stw r0, 0x1BC(r4)
    mfspr r0, GQR7
    stw r0, 0x1C0(r4)

    mfdsisr r5
    mfdar r6

    stwu r1, -8(r1)
    b fn_801D8A44
    // clang-format on
}
