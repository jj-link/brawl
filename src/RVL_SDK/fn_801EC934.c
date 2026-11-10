#include <types.h>
#include <revolution/MTX.h>
#pragma force_active on

extern const float lbl_805A3758;

asm void fn_801EC934(Mtx m, const Quaternion* q)
{
    nofralloc
    psq_l f4, 0(r4), 0, 0
    psq_l f5, 8(r4), 0, 0
    ps_mul f6, f4, f4
    lfs f1, lbl_805A3758(r0)
    ps_merge10 f9, f4, f4
    fsubs f0, f1, f1
    ps_madd f8, f5, f5, f6
    ps_muls1 f10, f5, f5
    fadds f2, f1, f1
    psq_st f0, 0xc(r3), 1, 0
    ps_sum0 f3, f8, f8, f8
    ps_mul f7, f5, f5
    psq_st f0, 0x2c(r3), 1, 0
    ps_madd f12, f4, f9, f10
    fres f13, f3
    ps_nmsub f3, f3, f13, f2
    ps_muls1 f11, f9, f5
    ps_msub f10, f4, f9, f10
    ps_mul f3, f13, f3
    ps_madds0 f9, f4, f5, f11
    ps_sum1 f8, f7, f8, f6
    fmuls f3, f3, f2
    ps_nmsub f11, f11, f2, f9
    ps_sum0 f6, f6, f6, f6
    ps_mul f9, f9, f3
    ps_mul f11, f11, f3
    ps_nmsub f8, f8, f3, f1
    ps_mul f12, f12, f3
    psq_st f9, 0x8(r3), 1, 0
    ps_mul f10, f10, f3
    ps_merge10 f7, f11, f0
    ps_merge00 f5, f12, f8
    ps_merge10 f4, f8, f10
    ps_merge01 f13, f11, f9
    psq_st f7, 0x18(r3), 0, 0
    ps_nmsub f6, f6, f3, f1
    psq_st f5, 0x10(r3), 0, 0
    psq_st f6, 0x28(r3), 1, 0
    psq_st f4, 0x0(r3), 0, 0
    psq_st f13, 0x20(r3), 0, 0
    blr
}
