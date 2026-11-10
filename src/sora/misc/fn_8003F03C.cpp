#include <types.h>
#pragma force_active on
#pragma scheduling off
extern "C" const f32 lbl_805A1728;
extern "C" const f32 lbl_805A172C;
extern "C" void fn_8003F03C(f32* p, f32 x, f32 y, f32 z) {
    register f32 b, a, one, zero;
    zero = lbl_805A1728;
    one = lbl_805A172C;
    register f32* dst = p;
    asm {
        ps_merge00 a, one, zero
        ps_merge00 b, zero, one
        psq_st a, 0(dst), 0, 0
        psq_st zero, 8(dst), 0, 0
        psq_st b, 16(dst), 0, 0
        psq_st zero, 24(dst), 0, 0
        psq_st zero, 32(dst), 0, 0
        psq_st a, 40(dst), 0, 0
    }
    p[3] = x;
    p[7] = y;
    p[11] = z;
}