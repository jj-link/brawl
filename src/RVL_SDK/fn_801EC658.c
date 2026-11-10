#pragma force_active on
extern const float lbl_805A3758;
extern const float lbl_805A375C;

asm void fn_801EC658(void)
{
    nofralloc
    frsp f5, f1
    ori r0, r4, 0x20
    frsp f4, f2
    cmplwi r0, 0x78
    lfs f0, lbl_805A375C(r0)
    ps_neg f2, f5
    lfs f1, lbl_805A3758(r0)
    beq L_78
    cmplwi r0, 0x79
    beq L_79
    cmplwi r0, 0x7a
    beq L_7a
    blr
L_78:
    ps_merge00 f3, f5, f4
    psq_st f1, 0(r3), 1, 0
    ps_merge00 f1, f4, f2
    psq_st f0, 4(r3), 0, 0
    psq_st f0, 12(r3), 0, 0
    psq_st f0, 28(r3), 0, 0
    psq_st f0, 44(r3), 1, 0
    psq_st f3, 36(r3), 0, 0
    psq_st f1, 20(r3), 0, 0
    blr
L_79:
    ps_merge00 f3, f4, f0
    psq_st f0, 24(r3), 0, 0
    ps_merge00 f1, f0, f1
    ps_merge00 f2, f2, f0
    ps_merge00 f0, f5, f0
    psq_st f3, 0(r3), 0, 0
    psq_st f3, 40(r3), 0, 0
    psq_st f1, 16(r3), 0, 0
    psq_st f0, 8(r3), 0, 0
    psq_st f2, 32(r3), 0, 0
    blr
L_7a:
    ps_merge00 f3, f5, f4
    psq_st f0, 8(r3), 0, 0
    ps_merge00 f2, f4, f2
    ps_merge00 f1, f1, f0
    psq_st f0, 24(r3), 0, 0
    psq_st f0, 32(r3), 0, 0
    psq_st f3, 16(r3), 0, 0
    psq_st f2, 0(r3), 0, 0
    psq_st f1, 40(r3), 0, 0
    blr
}
