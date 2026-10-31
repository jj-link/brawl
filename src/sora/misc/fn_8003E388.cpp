#pragma force_active on
#include <types.h>

#define REG_ regist##er
#define ASM_ as##m

extern "C" ASM_ void fn_8003E388(REG_ const float* src, REG_ float* dst)
{
    psq_l f0, 0(r3), 0, 0
    psq_l f1, 8(r3), 0, 0
    psq_l f2, 16(r3), 0, 0
    psq_l f3, 24(r3), 0, 0
    psq_l f4, 32(r3), 0, 0
    psq_l f5, 40(r3), 0, 0
    psq_st f0, 0(r4), 0, 0
    psq_st f1, 8(r4), 0, 0
    psq_st f2, 16(r4), 0, 0
    psq_st f3, 24(r4), 0, 0
    psq_st f4, 32(r4), 0, 0
    psq_st f5, 40(r4), 0, 0
}
