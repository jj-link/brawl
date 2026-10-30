#pragma force_active on
#include <types.h>

extern float lbl_805A1728;

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define REG_ PASTE(regist, er)

extern "C" BLOCK void fn_8003E3BC(REG_ const float* m, REG_ const float* vec,
                                  REG_ float* out)
{
    lfs      f0, lbl_805A1728
    psq_l    f2, 0x8(r4), 1, 0
    psq_l    f1, 0x0(r4), 0, 0
    psq_l    f3, 0x0(r3), 0, 0
    ps_merge00 f2, f2, f0
    psq_l    f0, 0x10(r3), 0, 0
    psq_l    f4, 0x20(r3), 0, 0
    ps_mul   f3, f3, f1
    psq_l    f5, 0x8(r3), 0, 0
    ps_mul   f0, f0, f1
    ps_mul   f4, f4, f1
    psq_l    f6, 0x18(r3), 0, 0
    psq_l    f1, 0x28(r3), 0, 0
    ps_madd  f3, f5, f2, f3
    ps_madd  f0, f6, f2, f0
    ps_madd  f4, f1, f2, f4
    ps_sum0  f3, f3, f3, f3
    ps_sum0  f0, f0, f0, f0
    ps_sum0  f4, f4, f2, f4
    psq_st   f3, 0x0(r5), 1, 0
    psq_st   f0, 0x4(r5), 1, 0
    psq_st   f4, 0x8(r5), 1, 0
}
