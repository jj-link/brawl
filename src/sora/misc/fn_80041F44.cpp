#include <types.h>
#pragma force_active on

extern "C" void fn_80041F44(register const f32* lhs, register const f32* rhs, register f32* pOut) {
    register f32 f0, f1, f2, f3, f4, f5;
    asm {
        psq_l f2, 0(lhs), 0, 0
        psq_l f1, 0(rhs), 0, 0
        psq_l f5, 8(lhs), 0, 0
        psq_l f4, 8(rhs), 0, 0
        ps_sub f0, f2, f1
        ps_sub f3, f5, f4
        ps_sel f0, f0, f1, f2
        ps_sel f1, f3, f5, f4
        psq_st f0, 0(pOut), 0, 0
        psq_st f1, 8(pOut), 0, 0
    }
}
