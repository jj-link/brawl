#include <types.h>
#pragma force_active on
#pragma scheduling off
extern f32 lbl_805A2C40;
extern f32 lbl_805A2C44;
extern "C" void fn_80162774(f32* p) {
    register f32* base = p;
    register f32 zero = lbl_805A2C40;
    register f32 one = lbl_805A2C44;
    register f32 pair;
    asm { psq_st zero, 8(base), 0, 0 }
    asm { ps_merge00 pair, one, zero }
    asm { psq_st zero, 24(base), 0, 0 }
    asm { psq_st pair, 0(base), 0, 0 }
    asm { psq_st pair, 16(base), 0, 0 }
    p[8] = one;
}