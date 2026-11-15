#include <revolution/MTX.h>
#include <types.h>
#pragma force_active on
extern const f32 lbl_8059EA60[2];
asm void fn_801EC284(const Mtx a, const Mtx* b, Mtx* ab, u32 count)
{
    nofralloc
    stwu r1, -0x60(r1)
    stfd f31, 0x50(r1)
    psq_st f31, 0x58(r1), 0, 0
    stfd f30, 0x40(r1)
    psq_st f30, 0x48(r1), 0, 0
    stfd f29, 0x30(r1)
    psq_st f29, 0x38(r1), 0, 0
    stfd f28, 0x20(r1)
    psq_st f28, 0x28(r1), 0, 0
    stfd f27, 0x10(r1)
    psq_st f27, 0x18(r1), 0, 0
    subi r0, r6, 0x1
    psq_l f0, 0x0(r3), 0, 0
    psq_l f1, 0x8(r3), 0, 0
    la r6, lbl_8059EA60
    psq_l f2, 0x10(r3), 0, 0
    psq_l f3, 0x18(r3), 0, 0
    psq_l f4, 0x20(r3), 0, 0
    psq_l f5, 0x28(r3), 0, 0
    mtctr r0
    psq_l f6, 0x0(r4), 0, 0
    psq_l f7, 0x8(r4), 0, 0
    ps_muls0 f12, f6, f0
    psq_l f8, 0x10(r4), 0, 0
    ps_muls0 f31, f6, f2
    psq_l f10, 0x20(r4), 0, 0
    ps_muls0 f29, f6, f4
    psq_l f9, 0x18(r4), 0, 0
    ps_madds1 f12, f8, f0, f12
    psq_l f27, 0x0(r6), 0, 0
    ps_madds1 f31, f8, f2, f31
    psq_l f11, 0x28(r4), 0, 0
    ps_madds1 f29, f8, f4, f29
    ps_muls0 f13, f7, f0
    ps_muls0 f30, f7, f2
    ps_muls0 f28, f7, f4
    ps_madds0 f12, f10, f1, f12
    ps_madds0 f31, f10, f3, f31
    ps_madds0 f29, f10, f5, f29
    ps_madds1 f13, f9, f0, f13
    psq_st f12, 0x0(r5), 0, 0
    ps_madds1 f30, f9, f2, f30
    ps_madds1 f28, f9, f4, f28
    psq_st f31, 0x10(r5), 0, 0
loop:
    ps_madds0 f13, f11, f1, f13
    psq_l f6, 0x30(r4), 0, 0
    ps_madds0 f30, f11, f3, f30
    psq_st f29, 0x20(r5), 0, 0
    ps_madds0 f28, f11, f5, f28
    psq_l f8, 0x40(r4), 0, 0
    ps_madd f13, f27, f1, f13
    psq_l f10, 0x50(r4), 0, 0
    ps_muls0 f12, f6, f0
    psq_l f7, 0x38(r4), 0, 0
    ps_muls0 f31, f6, f2
    psq_l f9, 0x48(r4), 0, 0
    psq_st f13, 0x8(r5), 0, 0
    ps_madd f30, f27, f3, f30
    ps_madds1 f12, f8, f0, f12
    psq_l f11, 0x58(r4), 0, 0
    ps_muls0 f29, f6, f4
    addi r4, r4, 0x30
    psq_st f30, 0x18(r5), 0, 0
    ps_madd f28, f27, f5, f28
    ps_madds1 f31, f8, f2, f31
    ps_madds1 f29, f8, f4, f29
    psq_st f28, 0x28(r5), 0, 0
    ps_madds0 f12, f10, f1, f12
    ps_muls0 f13, f7, f0
    ps_muls0 f30, f7, f2
    ps_muls0 f28, f7, f4
    psq_st f12, 0x30(r5), 0, 0
    ps_madds0 f31, f10, f3, f31
    ps_madds0 f29, f10, f5, f29
    ps_madds1 f13, f9, f0, f13
    psq_st f31, 0x40(r5), 0, 0
    ps_madds1 f30, f9, f2, f30
    ps_madds1 f28, f9, f4, f28
    addi r5, r5, 0x30
    bdnz loop
    ps_madds0 f13, f11, f1, f13
    psq_st f29, 0x20(r5), 0, 0
    ps_madds0 f30, f11, f3, f30
    ps_madds0 f28, f11, f5, f28
    ps_madd f13, f27, f1, f13
    ps_madd f30, f27, f3, f30
    ps_madd f28, f27, f5, f28
    psq_st f13, 0x8(r5), 0, 0
    psq_st f30, 0x18(r5), 0, 0
    psq_st f28, 0x28(r5), 0, 0
    psq_l f31, 0x58(r1), 0, 0
    lfd f31, 0x50(r1)
    psq_l f30, 0x48(r1), 0, 0
    lfd f30, 0x40(r1)
    psq_l f29, 0x38(r1), 0, 0
    lfd f29, 0x30(r1)
    psq_l f28, 0x28(r1), 0, 0
    lfd f28, 0x20(r1)
    psq_l f27, 0x18(r1), 0, 0
    lfd f27, 0x10(r1)
    addi r1, r1, 0x60
    blr
}