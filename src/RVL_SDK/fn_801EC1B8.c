#include <types.h>

#pragma force_active on

extern char lbl_8059EA60[];

asm void fn_801EC1B8(void)
{
    nofralloc
    stwu r1, -0x40(r1)
    psq_l f0, 0x0(r3), 0, 0
    stfd f14, 0x8(r1)
    psq_l f6, 0x0(r4), 0, 0
    lis r6, lbl_8059EA60@ha
    psq_l f7, 0x8(r4), 0, 0
    stfd f15, 0x10(r1)
    addi r6, r6, lbl_8059EA60@l
    stfd f31, 0x28(r1)
    psq_l f8, 0x10(r4), 0, 0
    ps_muls0 f12, f6, f0
    psq_l f2, 0x10(r3), 0, 0
    ps_muls0 f13, f7, f0
    psq_l f31, 0x0(r6), 0, 0
    ps_muls0 f14, f6, f2
    psq_l f9, 0x18(r4), 0, 0
    ps_muls0 f15, f7, f2
    psq_l f1, 0x8(r3), 0, 0
    ps_madds1 f12, f8, f0, f12
    psq_l f3, 0x18(r3), 0, 0
    ps_madds1 f14, f8, f2, f14
    psq_l f10, 0x20(r4), 0, 0
    ps_madds1 f13, f9, f0, f13
    psq_l f11, 0x28(r4), 0, 0
    ps_madds1 f15, f9, f2, f15
    psq_l f4, 0x20(r3), 0, 0
    psq_l f5, 0x28(r3), 0, 0
    ps_madds0 f12, f10, f1, f12
    ps_madds0 f13, f11, f1, f13
    ps_madds0 f14, f10, f3, f14
    ps_madds0 f15, f11, f3, f15
    psq_st f12, 0x0(r5), 0, 0
    ps_muls0 f2, f6, f4
    ps_madds1 f13, f31, f1, f13
    ps_muls0 f0, f7, f4
    psq_st f14, 0x10(r5), 0, 0
    ps_madds1 f15, f31, f3, f15
    psq_st f13, 0x8(r5), 0, 0
    ps_madds1 f2, f8, f4, f2
    ps_madds1 f0, f9, f4, f0
    ps_madds0 f2, f10, f5, f2
    lfd f14, 0x8(r1)
    psq_st f15, 0x18(r5), 0, 0
    ps_madds0 f0, f11, f5, f0
    psq_st f2, 0x20(r5), 0, 0
    ps_madds1 f0, f31, f5, f0
    lfd f15, 0x10(r1)
    psq_st f0, 0x28(r5), 0, 0
    lfd f31, 0x28(r1)
    addi r1, r1, 0x40
    blr
}
