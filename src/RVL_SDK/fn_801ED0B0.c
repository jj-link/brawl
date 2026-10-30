#include <types.h>
#include <revolution/MTX/mtx.h>
#pragma force_active on

#define REG_ regist##er
#define ASM_ as##m

ASM_ void fn_801ED0B0(REG_ const Vec* a, REG_ const Vec* b, REG_ Vec* prod) {
    psq_l f1, 0(r4), 0, 0
    lfs f2, 8(r3)
    psq_l f0, 0(r3), 0, 0
    ps_merge10 f6, f1, f1
    lfs f3, 8(r4)
    ps_mul f4, f1, f2
    ps_muls0 f7, f1, f0
    ps_msub f5, f0, f3, f4
    ps_msub f8, f0, f6, f7
    ps_merge11 f9, f5, f5
    ps_merge01 f10, f5, f8
    psq_st f9, 0(r5), 1, 0
    ps_neg f10, f10
    psq_st f10, 4(r5), 0, 0
}
