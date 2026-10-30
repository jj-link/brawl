#pragma force_active on

#define REG_ regist##er
#define ASM_ as##m

extern "C" ASM_ void mulPos__6MatrixFPC5Vec3fP5Vec3f(
    REG_ const float* mtx, REG_ const float* vec, REG_ float* out)
{
    psq_l  f0,  0(r4), 0, 0
    psq_l  f2,  0(r3), 0, 0
    psq_l  f4, 32(r3), 0, 0
    psq_l  f3, 16(r3), 0, 0
    ps_mul f2, f2, f0
    ps_mul f4, f4, f0
    psq_l  f1,  8(r4), 1, 0
    ps_mul f3, f3, f0
    psq_l  f5,  8(r3), 0, 0
    psq_l  f0, 24(r3), 0, 0
    psq_l  f6, 40(r3), 0, 0
    ps_madd f2, f5, f1, f2
    ps_madd f3, f0, f1, f3
    ps_madd f4, f6, f1, f4
    ps_sum0 f2, f2, f2, f2
    ps_sum0 f3, f3, f3, f3
    ps_sum0 f4, f4, f1, f4
    psq_st f2,  0(r5), 1, 0
    psq_st f3,  4(r5), 1, 0
    psq_st f4,  8(r5), 1, 0
}
