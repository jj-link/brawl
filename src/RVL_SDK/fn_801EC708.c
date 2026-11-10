#include <types.h>
#pragma force_active on

extern f32 lbl_805A3760;
extern f32 lbl_805A3764;

asm void fn_801EC708(void)
{
    nofralloc
    psq_l f3, 0(r4), 0, 0
    frsp f11, f2
    lfs f10, lbl_805A3760(r0)
    frsp f12, f1
    ps_mul f4, f3, f3
    lfs f2, 0x8(r4)
    fadds f8, f10, f10
    lfs f9, lbl_805A3764(r0)
    fsubs f1, f10, f10
    ps_madd f5, f2, f2, f4
    fsubs f0, f8, f11
    ps_merge00 f11, f11, f11
    ps_sum0 f6, f5, f2, f4
    frsqrte f7, f6
    fmuls f4, f7, f7
    fmuls f5, f7, f10
    fnmsubs f4, f4, f6, f9
    fmuls f7, f4, f5
    ps_muls0 f3, f3, f7
    ps_muls0 f2, f2, f7
    ps_muls0 f6, f3, f0
    ps_muls0 f7, f2, f0
    ps_muls0 f10, f3, f12
    ps_muls1 f5, f6, f3
    ps_muls0 f4, f6, f3
    ps_muls0 f6, f6, f2
    fnmsubs f0, f2, f12, f5
    ps_neg f3, f10
    fmadds f8, f2, f12, f5
    ps_sum0 f4, f4, f0, f11
    ps_sum0 f0, f3, f1, f6
    ps_muls0 f7, f7, f2
    ps_sum0 f9, f6, f1, f10
    psq_st f4, 0(r3), 0, 0
    ps_sum0 f3, f6, f6, f3
    ps_sum1 f5, f11, f8, f5
    psq_st f0, 0x18(r3), 0, 0
    ps_sum0 f7, f7, f1, f11
    ps_sum1 f6, f10, f3, f6
    psq_st f9, 0x8(r3), 0, 0
    psq_st f5, 0x10(r3), 0, 0
    psq_st f6, 0x20(r3), 0, 0
    psq_st f7, 0x28(r3), 0, 0
    blr
}
