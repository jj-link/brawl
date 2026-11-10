#include <types.h>
#pragma force_active on

extern "C" void fn_80042034(register const f32* in, register f32* out) {
    register f32 f0, f1, f2, f3, f4, f5;
    f1 = in[0];
    f0 = in[1];
    out[2] = f1;
    out[3] = f0;
    asm { psq_l f2, 8(in), 0, 0 }
    asm { psq_l f4, 16(in), 0, 0 }
    asm { psq_l f3, 8(out), 0, 0 }
    out[0] = f1;
    out[1] = f0;
    asm { ps_sub f1, f3, f2 }
    asm { ps_sel f3, f1, f3, f2 }
    asm { psq_l f1, 0(out), 0, 0 }
    asm { ps_sub f0, f1, f2 }
    asm { ps_sub f5, f3, f4 }
    asm { ps_sel f0, f0, f2, f1 }
    asm { ps_sel f2, f5, f3, f4 }
    asm { ps_sub f1, f0, f4 }
    asm { psq_st f2, 8(out), 0, 0 }
    asm { ps_sel f0, f1, f4, f0 }
    asm { psq_st f0, 0(out), 0, 0 }
}
