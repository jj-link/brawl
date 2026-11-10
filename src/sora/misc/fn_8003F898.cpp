#include <types.h>
#pragma force_active on

extern "C" void fn_8003F898(const f32* src, f32* dst) {
    register f32 a, b, c, e;
    register const f32* s = src;
    register f32* d = dst;
    asm { psq_l a, 0(s), 0, 0 }
    asm { psq_l b, 16(s), 0, 0 }
    asm { ps_merge00 c, a, b }
    asm { ps_merge11 e, a, b }
    asm { psq_l a, 8(s), 0, 0 }
    asm { psq_l b, 24(s), 0, 0 }
    asm { psq_st c, 0(d), 0, 0 }
    asm { ps_merge00 c, a, b }
    asm { psq_st e, 16(d), 0, 0 }
    asm { ps_merge11 e, a, b }
    asm { psq_l a, 32(s), 0, 0 }
    asm { psq_l b, 48(s), 0, 0 }
    asm { psq_st c, 32(d), 0, 0 }
    asm { ps_merge00 c, a, b }
    asm { psq_st e, 48(d), 0, 0 }
    asm { ps_merge11 e, a, b }
    asm { psq_l a, 40(s), 0, 0 }
    asm { psq_l b, 56(s), 0, 0 }
    asm { psq_st c, 8(d), 0, 0 }
    asm { ps_merge00 c, a, b }
    asm { psq_st e, 24(d), 0, 0 }
    asm { ps_merge11 e, a, b }
    asm { psq_st c, 40(d), 0, 0 }
    asm { psq_st e, 56(d), 0, 0 }
}
