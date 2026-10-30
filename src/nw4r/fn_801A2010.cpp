#include <types.h>
#pragma force_active on

#define REG_ regist##er
#define ASM_ as##m

extern "C" void fn_801A2010(REG_ float* out, REG_ const float* vec,
                           REG_ const float* m) {
    // clang-format off
    ASM_ {
        psq_l f2, 16(r5), 1, 0
        psq_l f3, 20(r5), 0, 0
        psq_l f0, 0(r5), 1, 0
        psq_l f1, 4(r5), 0, 0
        ps_merge10 f7, f3, f2
        psq_l f5, 36(r5), 0, 0
        psq_l f4, 32(r5), 1, 0
        ps_merge10 f6, f1, f0
        ps_mul f12, f5, f7
        ps_merge10 f8, f5, f4
        ps_mul f10, f3, f6
        ps_mul f9, f0, f5
        ps_mul f11, f1, f8
        ps_msub f12, f3, f8, f12
        ps_msub f10, f1, f7, f10
        ps_msub f11, f5, f6, f11
        ps_mul f7, f0, f12
        ps_sub f6, f6, f6
        ps_msub f9, f1, f4, f9
        ps_madd f7, f2, f11, f7
        stfs f6, 8(r3)
        ps_madd f7, f4, f10, f7
        ps_cmpo0 cr0, f7, f6
        bne not_zero
        psq_st f6, 0(r3), 0, 0
        blr
not_zero:
        fres f0, f7
        psq_l f1, 16(r4), 0, 0
        psq_l f2, 8(r4), 1, 0
        psq_l f3, 24(r4), 1, 0
        ps_add f6, f0, f0
        ps_mul f5, f0, f0
        ps_nmsub f0, f7, f5, f6
        ps_merge00 f6, f2, f3
        ps_muls0 f11, f11, f0
        ps_muls0 f9, f9, f0
        psq_l f0, 0(r4), 0, 0
        ps_merge00 f4, f0, f1
        ps_merge11 f5, f0, f1
        ps_muls0 f0, f4, f11
        ps_madds1 f0, f5, f11, f0
        ps_madds0 f0, f6, f9, f0
        psq_st f0, 0(r3), 0, 0
    }
    // clang-format on
}
