#include <types.h>
#include <mt/mt_matrix.h>
#pragma force_active on

extern f32 lbl_8059C788[2];

void Matrix::mul(const Matrix* mulMatrix, Matrix* outMatrix) const {
    register const f32* pA = (const f32*)this;
    register const f32* pB = (const f32*)mulMatrix;
    register f32* pOut = (f32*)outMatrix;
    register const f32* pL = lbl_8059C788;
    register f32 a0, a1, a2, a3, a4, a5, b0, b1, b2, r0, r1, r2;

    asm {
        psq_l a0, 0(pA), 0, 0
        psq_l b0, 0(pB), 0, 0
        psq_l a2, 16(pA), 0, 0
        psq_l a4, 32(pA), 0, 0
        ps_muls0 r0, b0, a0
        psq_l b1, 16(pB), 0, 0
        ps_muls0 r1, b0, a2
        ps_muls0 r2, b0, a4
        psq_l b2, 32(pB), 0, 0
        ps_madds1 r0, b1, a0, r0
        psq_l a1, 8(pA), 0, 0
        ps_madds1 r1, b1, a2, r1
        ps_madds1 r2, b1, a4, r2
        psq_l a3, 24(pA), 0, 0
        ps_madds0 r0, b2, a1, r0
        psq_l a5, 40(pA), 0, 0
        ps_madds0 r1, b2, a3, r1
        psq_l b0, 8(pB), 0, 0
        ps_madds0 r2, b2, a5, r2
        psq_st r0, 0(pOut), 0, 0
        ps_muls0 r0, b0, a0
        psq_l b1, 24(pB), 0, 0
        psq_st r1, 16(pOut), 0, 0
        ps_muls0 r1, b0, a2
        ps_madds1 r0, b1, a0, r0
        psq_l b2, 40(pB), 0, 0
        psq_st r2, 32(pOut), 0, 0
        ps_muls0 r2, b0, a4
        ps_madds1 r1, b1, a2, r1
        ps_madds0 r0, b2, a1, r0
        ps_madds1 r2, b1, a4, r2
        psq_l a0, 0(pL), 0, 0
        ps_madds0 r1, b2, a3, r1
        ps_madds1 r0, a0, a1, r0
        ps_madds0 r2, b2, a5, r2
        ps_madds1 r1, a0, a3, r1
        psq_st r0, 8(pOut), 0, 0
        ps_madds1 r2, a0, a5, r2
        psq_st r1, 24(pOut), 0, 0
        psq_st r2, 40(pOut), 0, 0
    }
}
