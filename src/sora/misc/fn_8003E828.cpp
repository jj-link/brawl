#pragma force_active on
#include <types.h>

#define REG_ regist##er
#define ASM_ as##m

extern "C" ASM_ void fn_8003E828(REG_ const float* a, REG_ const float* b, REG_ float* out)
{
    psq_l  f0,  0(r4), 0, 0
    psq_l  f2,  0(r3), 0, 0
    psq_l  f3, 16(r3), 0, 0
    psq_l  f4, 32(r3), 0, 0
    ps_mul f2, f2, f0
    ps_mul f3, f3, f0
    psq_l  f1,  8(r4), 1, 0
    ps_mul f4, f4, f0
    psq_st f2,  0(r5), 0, 0
    psq_l  f2,  8(r3), 0, 0
    psq_st f3, 16(r5), 0, 0
    psq_l  f3, 24(r3), 0, 0
    ps_mul f2, f2, f1
    psq_st f4, 32(r5), 0, 0
    psq_l  f4, 40(r3), 0, 0
    ps_mul f3, f3, f1
    psq_st f2,  8(r5), 0, 0
    ps_mul f4, f4, f1
    psq_st f3, 24(r5), 0, 0
    psq_st f4, 40(r5), 0, 0
}
