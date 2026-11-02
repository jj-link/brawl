#pragma force_active on

extern "C" int fn_801B62B8(int, int);
extern "C" void fn_801B601C(char*, const void*);

#define REG_ regist##er
#define ASM_ as##m

extern "C" ASM_ void fn_8000E710(int a, int b, int c, int d, float f) {
    // clang-format off
    stwu r1, -0x30(r1)
    mflr r0
    stw  r0, 0x34(r1)
    stfd f31, 0x20(r1)
    psq_st f31, 0x28(r1), 0, 0
    mr   r3, r4
    fmr  f31, f1
    addi r4, r1, 0x14
    stw  r31, 0x1c(r1)
    mr   r31, r6
    stw  r30, 0x18(r1)
    mr   r30, r5
    bl fn_801B62B8
    mr   r3, r30
    addi r4, r1, 0x10
    bl fn_801B62B8
    psq_l  f2, 0x14(r1), 0, 2
    psq_l  f0, 0x10(r1), 0, 2
    psq_l  f3, 0x16(r1), 0, 2
    psq_l  f1, 0x12(r1), 0, 2
    ps_sub f0, f0, f2
    ps_sub f1, f1, f3
    ps_madds0 f2, f0, f31, f2
    ps_madds0 f3, f1, f31, f3
    psq_st f2, 0xc(r1), 0, 2
    psq_st f3, 0xe(r1), 0, 2
    mr   r3, r31
    addi r4, r1, 0x8
    lwz  r0, 0xc(r1)
    stw  r0, 0x8(r1)
    bl fn_801B601C
    psq_l f31, 0x28(r1), 0, 0
    lwz  r0, 0x34(r1)
    lfd  f31, 0x20(r1)
    lwz  r31, 0x1c(r1)
    lwz  r30, 0x18(r1)
    mtlr r0
    addi r1, r1, 0x30
    blr
    // clang-format on
}