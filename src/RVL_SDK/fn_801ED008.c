#include <revolution/MTX/mtx.h>
#pragma force_active on

extern float lbl_805A3790;
extern float lbl_805A3794;

#define PASTE(x, y) x##y
#define ASM_ PASTE(as, m)
#define REG_ PASTE(regist, er)

ASM_ void fn_801ED008(REG_ const Vec* in, REG_ Vec* out) {
    psq_l f2, 0(r3), 0, 0
    psq_l f3, 8(r3), 1, 0
    ps_mul f5, f2, f2
    lfs f0, lbl_805A3790
    lfs f1, lbl_805A3794
    ps_madd f4, f3, f3, f5
    ps_sum0 f4, f4, f3, f5
    frsqrte f5, f4
    fmuls f6, f5, f5
    fmuls f0, f5, f0
    fnmsubs f6, f6, f4, f1
    fmuls f5, f6, f0
    ps_muls0 f2, f2, f5
    ps_muls0 f3, f3, f5
    psq_st f2, 0(r4), 0, 0
    psq_st f3, 8(r4), 1, 0
    blr
}
