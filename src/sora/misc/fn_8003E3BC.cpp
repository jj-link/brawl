#include <types.h>
#include <nw4r/math/math_types.h>
#pragma force_active on

extern "C" const float lbl_805A1728;

extern "C" void fn_8003E3BC(const nw4r::math::MTX34* m, const nw4r::math::VEC3* v, nw4r::math::VEC3* out)
{
    register f32 zero = lbl_805A1728;
    register f32 vxy, vz, r0a, r1a, r2a, r0b, r1b, r2b;
    register const f32* pm = (const f32*)m;
    register const f32* pv = (const f32*)v;
    register f32* po = (f32*)out;

    asm {
        psq_l vz, 8(pv), 1, 0
        psq_l vxy, 0(pv), 0, 0
        ps_merge00 vz, vz, zero
        psq_l r0a, 0(pm), 0, 0
        psq_l r1a, 16(pm), 0, 0
        psq_l r2a, 32(pm), 0, 0
        ps_mul r0a, r0a, vxy
        psq_l r0b, 8(pm), 0, 0
        ps_mul r1a, r1a, vxy
        ps_mul r2a, r2a, vxy
        psq_l r1b, 24(pm), 0, 0
        psq_l r2b, 40(pm), 0, 0
        ps_madd r0a, r0b, vz, r0a
        ps_madd r1a, r1b, vz, r1a
        ps_madd r2a, r2b, vz, r2a
        ps_sum0 r0a, r0a, r0a, r0a
        ps_sum0 r1a, r1a, r1a, r1a
        ps_sum0 r2a, r2a, vz, r2a
        psq_st r0a, 0(po), 1, 0
        psq_st r1a, 4(po), 1, 0
        psq_st r2a, 8(po), 1, 0
    }
}
