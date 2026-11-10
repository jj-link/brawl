#include <types.h>
#pragma force_active on

extern f32 lbl_80532040[];
extern f32 *lbl_805A0D60;
extern u32 lbl_805A0D80;
extern u32 lbl_805A0DA0;
extern f32 lbl_805A3AB8;
extern f32 lbl_805A3ABC;
extern f32 lbl_805A3AC0;
extern f32 lbl_805A3AC4;
extern f32 lbl_805A3AC8;

asm void fn_8025D334(void *arg0, s32 arg1)
{
    nofralloc
    stwu r1, -0x80(r1)
    stfd f31, 0x70(r1)
    psq_st f31, 0x78(r1), 0, 0
    stfd f30, 0x60(r1)
    psq_st f30, 0x68(r1), 0, 0
    stfd f29, 0x50(r1)
    psq_st f29, 0x58(r1), 0, 0
    stfd f28, 0x40(r1)
    psq_st f28, 0x48(r1), 0, 0
    stfd f27, 0x30(r1)
    psq_st f27, 0x38(r1), 0, 0
    stfd f26, 0x20(r1)
    psq_st f26, 0x28(r1), 0, 0
    stfd f25, 0x10(r1)
    psq_st f25, 0x18(r1), 0, 0
    lis r5, lbl_80532040@ha
    li r7, 0x8
    addi r5, r5, lbl_80532040@l
    lfs f29, lbl_805A3AB8(r0)
    subi r10, r5, 0x8
    lfs f28, lbl_805A3ABC(r0)
    lfs f27, lbl_805A3AC0(r0)
    lfs f26, lbl_805A3AC4(r0)
    lfs f25, lbl_805A3AC8(r0)
    lwz r5, lbl_805A0D60(r0)
    mtctr r7
L_loop:
    psq_l f10, 0x0(r3), 0, 5
    psq_l f11, 0x0(r5), 0, 0
    lwz r0, 0xc(r3)
    lwz r8, 0x8(r3)
    ps_mul f10, f10, f11
    lwz r6, 0x4(r3)
    or. r0, r0, r8
    lhz r7, 0x2(r3)
L_top:
    cmpwi r0, 0x0
    bne L_4FC
    ps_merge00 f0, f10, f10
    cmpwi r6, 0x0
    psq_st f0, 0x8(r10), 0, 0
    bne L_468
    psq_st f0, 0x10(r10), 0, 0
    cmpwi r7, 0x0
    psq_st f0, 0x18(r10), 0, 0
    bne L_3F8
    psq_stu f0, 0x20(r10), 0, 0
    addi r3, r3, 0x10
    addi r5, r5, 0x20
    bdnz L_loop
    b L_5BC
L_3F8:
    ps_msub f2, f10, f28, f10
    psq_lu f11, 0x20(r5), 0, 0
    ps_sub f1, f28, f27
    lwz r6, 0x14(r3)
    ps_merge00 f9, f10, f10
    lhz r7, 0x12(r3)
    ps_msub f3, f10, f29, f2
    ps_merge11 f5, f10, f2
    ps_nmsub f4, f10, f1, f3
    ps_add f7, f9, f5
    psq_l f10, 0x10(r3), 0, 5
    lwz r0, 0x1c(r3)
    ps_sub f5, f9, f5
    ps_merge11 f6, f3, f4
    lwz r8, 0x18(r3)
    ps_add f8, f9, f6
    ps_sub f6, f9, f6
    psq_stu f7, 0x8(r10), 0, 0
    ps_merge10 f6, f6, f6
    psq_stu f8, 0x8(r10), 0, 0
    ps_merge10 f5, f5, f5
    or r0, r0, r8
    psq_stu f6, 0x8(r10), 0, 0
    ps_mul f10, f10, f11
    psq_stu f5, 0x8(r10), 0, 0
    addi r3, r3, 0x10
    bdnz L_top
    b L_5BC
L_468:
    psq_l f1, 0x4(r3), 0, 5
    psq_l f9, 0x8(r5), 0, 0
    lwz r0, 0x1c(r3)
    ps_mul f1, f1, f9
    lwz r8, 0x18(r3)
    lwz r6, 0x14(r3)
    lhz r7, 0x12(r3)
    ps_sub f3, f10, f1
    ps_add f2, f10, f1
    ps_mul f8, f3, f28
    ps_madd f4, f1, f29, f3
    ps_nmsub f5, f1, f29, f2
    ps_nmsub f6, f1, f26, f8
    ps_nmsub f7, f10, f27, f8
    ps_merge00 f4, f2, f4
    ps_sub f6, f6, f2
    ps_merge00 f5, f5, f3
    ps_msub f8, f3, f29, f6
    ps_merge11 f2, f2, f6
    psq_lu f10, 0x10(r3), 0, 5
    psq_lu f11, 0x20(r5), 0, 0
    ps_sub f7, f7, f8
    ps_add f9, f4, f2
    ps_sub f4, f4, f2
    ps_merge11 f3, f8, f7
    psq_stu f9, 0x8(r10), 0, 0
    or r0, r0, r8
    ps_add f0, f5, f3
    ps_sub f1, f5, f3
    psq_stu f0, 0x8(r10), 0, 0
    ps_merge10 f4, f4, f4
    ps_merge10 f1, f1, f1
    psq_stu f1, 0x8(r10), 0, 0
    ps_mul f10, f10, f11
    psq_stu f4, 0x8(r10), 0, 0
    bdnz L_top
    b L_5BC
L_4FC:
    psq_l f9, 0x4(r3), 0, 5
    psq_l f5, 0x8(r5), 0, 0
    ps_mul f9, f9, f5
    psq_l f2, 0x8(r3), 0, 5
    psq_l f6, 0x10(r5), 0, 0
    ps_merge01 f0, f10, f9
    psq_l f3, 0xc(r3), 0, 5
    ps_merge01 f1, f9, f10
    psq_l f7, 0x18(r5), 0, 0
    lwz r0, 0x1c(r3)
    ps_madd f4, f2, f6, f0
    ps_nmsub f5, f2, f6, f0
    lwz r8, 0x18(r3)
    ps_madd f6, f3, f7, f1
    lwz r6, 0x14(r3)
    ps_nmsub f7, f3, f7, f1
    lhz r7, 0x12(r3)
    ps_add f0, f4, f6
    ps_sub f8, f7, f5
    ps_msub f2, f7, f29, f6
    ps_sub f3, f4, f6
    ps_mul f8, f8, f28
    ps_add f1, f5, f2
    ps_sub f2, f5, f2
    ps_nmsub f6, f5, f26, f8
    ps_msub f4, f7, f27, f8
    ps_merge00 f1, f0, f1
    ps_sub f6, f6, f0
    ps_merge00 f2, f2, f3
    ps_madd f5, f3, f29, f6
    ps_merge11 f7, f0, f6
    psq_lu f10, 0x10(r3), 0, 5
    psq_lu f11, 0x20(r5), 0, 0
    ps_sub f4, f4, f5
    ps_add f3, f1, f7
    ps_sub f0, f1, f7
    ps_merge11 f4, f5, f4
    ps_mul f10, f10, f11
    ps_add f5, f2, f4
    ps_sub f6, f2, f4
    ps_merge10 f5, f5, f5
    psq_stu f3, 0x8(r10), 0, 0
    ps_merge10 f0, f0, f0
    psq_stu f6, 0x8(r10), 0, 0
    psq_stu f5, 0x8(r10), 0, 0
    or r0, r0, r8
    psq_stu f0, 0x8(r10), 0, 0
    bdnz L_top
L_5BC:
    lis r10, lbl_80532040@ha
    lwz r0, lbl_805A0D80(r0)
    addi r10, r10, lbl_80532040@l
    slwi r4, r4, 2
    psq_l f10, 0x0(r10), 0, 0
    slwi r5, r0, 2
    psq_l f11, 0x80(r10), 0, 0
    add r5, r4, r5
    lwz r0, lbl_805A0DA0(r0)
    li r3, 0x3
    ps_add f6, f10, f11
    psq_l f12, 0x40(r10), 0, 0
    psq_l f13, 0xc0(r10), 0, 0
    ps_sub f8, f10, f11
    add r6, r0, r4
    add r7, r0, r5
    ps_add f6, f6, f25
    ps_add f7, f12, f13
    ps_sub f9, f12, f13
    ps_add f8, f8, f25
    ps_add f0, f6, f7
    mtctr r3
L_614:
    ps_msub f9, f9, f29, f7
    psq_l f4, 0x20(r10), 0, 0
    ps_sub f3, f6, f7
    psq_l f5, 0x60(r10), 0, 0
    psq_l f6, 0xa0(r10), 0, 0
    psq_l f7, 0xe0(r10), 0, 0
    ps_add f1, f8, f9
    psq_l f10, 0x8(r10), 0, 0
    ps_sub f2, f8, f9
    psq_l f11, 0x88(r10), 0, 0
    ps_add f8, f6, f5
    psq_l f12, 0x48(r10), 0, 0
    ps_add f9, f4, f7
    psq_l f13, 0xc8(r10), 0, 0
    ps_sub f6, f6, f5
    addi r10, r10, 0x8
    ps_sub f4, f4, f7
    ps_add f7, f9, f8
    ps_sub f5, f9, f8
    ps_add f8, f6, f4
    ps_add f9, f0, f7
    ps_sub f30, f0, f7
    ps_mul f8, f8, f28
    ps_madd f6, f6, f26, f8
    ps_sub f6, f6, f7
    psq_st f9, 0x0(r6), 0, 6
    ps_msub f4, f4, f27, f8
    ps_add f9, f1, f6
    ps_msub f5, f5, f29, f6
    ps_sub f31, f1, f6
    psq_st f9, 0x8(r6), 0, 6
    ps_add f8, f2, f5
    ps_add f4, f4, f5
    psq_st f8, 0x10(r6), 0, 6
    ps_sub f9, f3, f4
    ps_add f0, f3, f4
    psq_st f9, 0x18(r6), 0, 6
    ps_sub f1, f2, f5
    ps_add f6, f10, f11
    psq_st f0, 0x0(r7), 0, 6
    ps_sub f8, f10, f11
    ps_add f6, f6, f25
    psq_st f1, 0x8(r7), 0, 6
    ps_add f7, f12, f13
    ps_sub f9, f12, f13
    psq_st f31, 0x10(r7), 0, 6
    addi r4, r4, 0x2
    add r6, r0, r4
    ps_add f0, f6, f7
    psq_st f30, 0x18(r7), 0, 6
    addi r5, r5, 0x2
    ps_add f8, f8, f25
    add r7, r0, r5
    bdnz L_614
    ps_msub f9, f9, f29, f7
    psq_l f4, 0x20(r10), 0, 0
    ps_sub f3, f6, f7
    psq_l f5, 0x60(r10), 0, 0
    psq_l f6, 0xa0(r10), 0, 0
    psq_l f7, 0xe0(r10), 0, 0
    ps_add f1, f8, f9
    ps_sub f2, f8, f9
    ps_add f8, f6, f5
    ps_add f9, f4, f7
    ps_sub f6, f6, f5
    ps_sub f4, f4, f7
    ps_add f7, f9, f8
    ps_sub f5, f9, f8
    ps_add f8, f6, f4
    ps_add f9, f0, f7
    ps_sub f30, f0, f7
    ps_mul f8, f8, f28
    ps_madd f6, f6, f26, f8
    psq_st f9, 0x0(r6), 0, 6
    ps_msub f4, f4, f27, f8
    ps_sub f6, f6, f7
    psq_st f30, 0x18(r7), 0, 6
    ps_add f9, f1, f6
    ps_msub f5, f5, f29, f6
    ps_sub f31, f1, f6
    psq_st f9, 0x8(r6), 0, 6
    ps_add f8, f2, f5
    ps_add f4, f4, f5
    psq_st f31, 0x10(r7), 0, 6
    psq_st f8, 0x10(r6), 0, 6
    ps_sub f9, f3, f4
    ps_add f0, f3, f4
    psq_st f9, 0x18(r6), 0, 6
    ps_sub f1, f2, f5
    psq_st f0, 0x0(r7), 0, 6
    psq_st f1, 0x8(r7), 0, 6
    psq_l f31, 0x78(r1), 0, 0
    lfd f31, 0x70(r1)
    psq_l f30, 0x68(r1), 0, 0
    lfd f30, 0x60(r1)
    psq_l f29, 0x58(r1), 0, 0
    lfd f29, 0x50(r1)
    psq_l f28, 0x48(r1), 0, 0
    lfd f28, 0x40(r1)
    psq_l f27, 0x38(r1), 0, 0
    lfd f27, 0x30(r1)
    psq_l f26, 0x28(r1), 0, 0
    lfd f26, 0x20(r1)
    psq_l f25, 0x18(r1), 0, 0
    lfd f25, 0x10(r1)
    addi r1, r1, 0x80
    blr
}
