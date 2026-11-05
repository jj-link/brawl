#pragma force_active on

#define REG_ regist##er
#define ASM_ as##m

extern "C" {
extern float lbl_805A1F90;
extern float lbl_805A1FA0;
int fn_800408C4(void*, void*, float*);
int fn_8004094C(void*, void*, float*);
}

extern "C" ASM_ void fn_800A46B4(
    REG_ void* a0, REG_ void* a1, REG_ void* a2, REG_ void* a3) {
    stwu   r1, -0x70(r1)
    mflr   r0
    stw    r0, 0x74(r1)
    stfd   f31, 0x60(r1)
    psq_st f31, 0x68(r1), 0, 0
    stfd   f30, 0x50(r1)
    psq_st f30, 0x58(r1), 0, 0
    stw    r31, 0x4c(r1)
    mr     r31, r6
    stw    r30, 0x48(r1)
    mr     r30, r5
    stw    r29, 0x44(r1)
    mr     r29, r4
    stw    r28, 0x40(r1)
    mr     r28, r3
    lfs    f1, 0xc(r4)
    lfs    f0, 0x4(r4)
    lfs    f3, 0x8(r4)
    fsubs  f2, f1, f0
    lfs    f0, 0x0(r4)
    lfs    f5, 0x8(r4)
    fsubs  f3, f3, f0
    lfs    f4, 0x0(r4)
    stfs   f2, 0x1c(r1)
    ps_sub f1, f4, f5
    lfs    f0, 0x0(r5)
    lwz    r0, 0x1c(r1)
    stfs   f3, 0x20(r1)
    ps_sub f6, f4, f5
    ps_sel f1, f1, f5, f4
    stw    r0, 0xc(r1)
    lwz    r0, 0x20(r1)
    ps_sel f6, f6, f4, f5
    fcmpo  cr0, f1, f0
    stfs   f2, 0x24(r1)
    lfs    f1, 0xc(r1)
    lwz    r3, 0x24(r1)
    fneg   f2, f1
    stw    r0, 0x10(r1)
    lfs    f8, 0xc(r4)
    lfs    f7, 0x4(r4)
    stfs   f3, 0x18(r1)
    ps_sub f31, f7, f8
    lfs    f1, 0x10(r1)
    ps_sub f30, f7, f8
    lwz    r0, 0x18(r1)
    stw    r3, 0x14(r1)
    ps_sel f31, f31, f8, f7
    ps_sel f30, f30, f7, f8
    stw    r0, 0x8(r1)
    stfs   f2, 0x28(r1)
    stfs   f1, 0x2c(r1)
    cror   eq, lt, eq
    bne    L_skip1
    fcmpo  cr0, f0, f6
    cror   eq, lt, eq
    bne    L_skip1
    mr     r3, r29
    mr     r4, r30
    addi   r5, r1, 0x30
    bl     fn_800408C4
    cmpwi  r3, 0
    beq    L_skip1
    lfs    f3, 0x4(r30)
    lfs    f2, 0x4(r31)
    lfs    f1, 0x2c(r1)
    lfs    f0, lbl_805A1F90(r2)
    fadds  f4, f3, f2
    fsubs  f5, f3, f2
    fcmpo  cr0, f1, f0
    bge    L_block2
    lfs    f0, 0x34(r1)
    fcmpo  cr0, f3, f0
    bge    L_block2
    fcmpo  cr0, f0, f4
    bge    L_block2
    lbz    r3, 0x145(r28)
    clrlwi. r0, r3, 31
    bne    L_block2
    rlwinm. r0, r3, 0, 30, 30
    beq    L_b3
    fsubs  f1, f0, f2
    lfs    f0, lbl_805A1FA0(r2)
    fadds  f1, f3, f1
    fmuls  f0, f1, f0
    stfs   f0, 0x4(r30)
    b      L_b4
L_b3:
    fsubs  f0, f0, f2
    stfs   f0, 0x4(r30)
L_b4:
    lbz    r0, 0x145(r28)
    ori    r0, r0, 0x1
    stb    r0, 0x145(r28)
L_block2:
    lfs    f1, 0x2c(r1)
    lfs    f0, lbl_805A1F90(r2)
    fcmpo  cr0, f1, f0
    ble    L_skip1
    lfs    f3, 0x4(r30)
    lfs    f2, 0x34(r1)
    fcmpo  cr0, f3, f2
    ble    L_skip1
    fcmpo  cr0, f2, f5
    ble    L_skip1
    lbz    r3, 0x145(r28)
    rlwinm. r0, r3, 0, 30, 30
    bne    L_skip1
    clrlwi. r0, r3, 31
    beq    L_b5
    lfs    f1, 0x4(r31)
    lfs    f0, lbl_805A1FA0(r2)
    fadds  f1, f2, f1
    fadds  f1, f3, f1
    fmuls  f0, f1, f0
    stfs   f0, 0x4(r30)
    b      L_b6
L_b5:
    lfs    f0, 0x4(r31)
    fadds  f0, f2, f0
    stfs   f0, 0x4(r30)
L_b6:
    lbz    r0, 0x145(r28)
    ori    r0, r0, 0x2
    stb    r0, 0x145(r28)
L_skip1:
    lfs    f0, 0x4(r30)
    fcmpo  cr0, f31, f0
    cror   eq, lt, eq
    bne    L_skip7
    fcmpo  cr0, f0, f30
    cror   eq, lt, eq
    bne    L_skip7
    mr     r3, r29
    mr     r4, r30
    addi   r5, r1, 0x30
    bl     fn_8004094C
    cmpwi  r3, 0
    beq    L_skip7
    lfs    f3, 0x0(r30)
    lfs    f2, 0x0(r31)
    lfs    f1, 0x28(r1)
    lfs    f0, lbl_805A1F90(r2)
    fadds  f4, f3, f2
    fsubs  f5, f3, f2
    fcmpo  cr0, f1, f0
    bge    L_block8
    lfs    f0, 0x30(r1)
    fcmpo  cr0, f5, f0
    bge    L_block8
    fcmpo  cr0, f0, f4
    bge    L_block8
    lbz    r3, 0x145(r28)
    rlwinm. r0, r3, 0, 29, 29
    bne    L_block8
    rlwinm. r0, r3, 0, 28, 28
    beq    L_b9
    fsubs  f1, f0, f2
    lfs    f0, lbl_805A1FA0(r2)
    fadds  f1, f3, f1
    fmuls  f0, f1, f0
    stfs   f0, 0x0(r30)
    b      L_b10
L_b9:
    fsubs  f0, f0, f2
    stfs   f0, 0x0(r30)
L_b10:
    lbz    r0, 0x145(r28)
    ori    r0, r0, 0x4
    stb    r0, 0x145(r28)
L_block8:
    lfs    f1, 0x28(r1)
    lfs    f0, lbl_805A1F90(r2)
    fcmpo  cr0, f1, f0
    ble    L_skip7
    lfs    f3, 0x0(r30)
    lfs    f2, 0x0(r31)
    lfs    f0, 0x30(r1)
    fadds  f1, f3, f2
    fcmpo  cr0, f1, f0
    ble    L_skip7
    fcmpo  cr0, f0, f5
    ble    L_skip7
    lbz    r3, 0x145(r28)
    rlwinm. r0, r3, 0, 28, 28
    bne    L_skip7
    rlwinm. r0, r3, 0, 29, 29
    beq    L_b11
    fadds  f1, f0, f2
    lfs    f0, lbl_805A1FA0(r2)
    fadds  f1, f3, f1
    fmuls  f0, f1, f0
    stfs   f0, 0x0(r30)
    b      L_b12
L_b11:
    fadds  f0, f0, f2
    stfs   f0, 0x0(r30)
L_b12:
    lbz    r0, 0x145(r28)
    ori    r0, r0, 0x8
    stb    r0, 0x145(r28)
L_skip7:
    psq_l  f31, 0x68(r1), 0, 0
    lfd    f31, 0x60(r1)
    psq_l  f30, 0x58(r1), 0, 0
    lfd    f30, 0x50(r1)
    lwz    r31, 0x4c(r1)
    lwz    r30, 0x48(r1)
    lwz    r29, 0x44(r1)
    lwz    r0, 0x74(r1)
    lwz    r28, 0x40(r1)
    mtlr   r0
    addi   r1, r1, 0x70
    blr
}
