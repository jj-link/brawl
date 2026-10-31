#pragma force_active on
#define PP_CAT_I(a, b) a##b
#define PP_CAT(a, b) PP_CAT_I(a, b)
#define ASSEMBLY PP_CAT(as, m)

extern void fn_801DD3A0(void);

ASSEMBLY void fn_801DD644(void) {
    nofralloc
    stw r0, 0(r4)
    stw r1, 4(r4)
    stw r2, 8(r4)
    stmw r6, 0x18(r4)
    mfspr r0, GQR1
    stw r0, 0x1a8(r4)
    mfspr r0, GQR2
    stw r0, 0x1ac(r4)
    mfspr r0, GQR3
    stw r0, 0x1b0(r4)
    mfspr r0, GQR4
    stw r0, 0x1b4(r4)
    mfspr r0, GQR5
    stw r0, 0x1b8(r4)
    mfspr r0, GQR6
    stw r0, 0x1bc(r4)
    mfspr r0, GQR7
    stw r0, 0x1c0(r4)
    stwu r1, -8(r1)
    b fn_801DD3A0
}
