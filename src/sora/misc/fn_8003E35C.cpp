#include <types.h>
#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define REG_ PASTE(regist, er)

extern float lbl_805A1728;
extern float lbl_805A172C;

extern "C" BLOCK void setIdentity__6MatrixFv(REG_ float* m)
{
    lfs f0, lbl_805A1728
    lfs f1, lbl_805A172C
    ps_merge00 f2, f1, f0
    ps_merge00 f1, f0, f1
    psq_st f2, 0x0(r3), 0, 0
    psq_st f0, 0x8(r3), 0, 0
    psq_st f1, 0x10(r3), 0, 0
    psq_st f0, 0x18(r3), 0, 0
    psq_st f0, 0x20(r3), 0, 0
    psq_st f2, 0x28(r3), 0, 0
}
