#pragma force_active on

#define REG_ regist##er
#define ASM_ as##m

extern "C" ASM_ void fn_80042034(REG_ const float* pIn, REG_ float* pOut) {
    // clang-format off
    lfs    f1,   0(r3)
    lfs    f0,   4(r3)
    stfs   f1,   8(r4)
    psq_l  f2,   8(r3), 0, 0
    stfs   f0,   0xc(r4)
    psq_l  f4,   16(r3), 0, 0
    psq_l  f3,   8(r4), 0, 0
    stfs   f1,   0(r4)
    ps_sub f1,   f3, f2
    stfs   f0,   4(r4)
    ps_sel f3,   f1, f3, f2
    psq_l  f1,   0(r4), 0, 0
    ps_sub f0,   f1, f2
    ps_sub f5,   f3, f4
    ps_sel f0,   f0, f2, f1
    ps_sel f2,   f5, f3, f4
    ps_sub f1,   f0, f4
    psq_st f2,   8(r4), 0, 0
    ps_sel f0,   f1, f4, f0
    psq_st f0,   0(r4), 0, 0
    blr
    // clang-format on
}
