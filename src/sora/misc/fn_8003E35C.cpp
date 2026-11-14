#include <types.h>
#include <mt/mt_matrix.h>
#pragma force_active on
#pragma scheduling off

extern "C" const float lbl_805A1728;
extern "C" const float lbl_805A172C;

void Matrix::setIdentity() {
    register Matrix* self = this;
    register f32 fr0, fr1, fr2;

    fr0 = lbl_805A1728;
    fr1 = lbl_805A172C;

    asm {
        ps_merge00 fr2, fr1, fr0
        ps_merge00 fr1, fr0, fr1
        psq_st fr2, 0(self), 0, 0
        psq_st fr0, 8(self), 0, 0
        psq_st fr1, 16(self), 0, 0
        psq_st fr0, 24(self), 0, 0
        psq_st fr0, 32(self), 0, 0
        psq_st fr2, 40(self), 0, 0
    }
}