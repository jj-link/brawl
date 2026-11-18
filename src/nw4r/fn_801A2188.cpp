#include <types.h>
#include <nw4r/math/math_types.h>
#pragma force_active on

using namespace nw4r::math;

extern "C" {
extern const float lbl_805A3340;
extern const float lbl_805A3344;

int fn_803F646C(float);
float fn_801622A0(float);
void fn_801ED008(const VEC3*, VEC3*);
}

extern "C" void fn_801A2188(MTX34* out, const MTX34* matrices, int uniform, int unused1, int unused2, int index) {
    VEC3 v(out->_01, out->_11, lbl_805A3340);
    VEC3 fallback(lbl_805A3340, lbl_805A3344, lbl_805A3340);
    int invalid = 0;

    if (fn_803F646C(v.x) == 1 || fn_803F646C(v.y) == 1 || fn_803F646C(v.z) == 1) {
        invalid = 1;
    }

    const VEC3* p = &v;
    if (invalid) {
        p = &fallback;
    }
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;

    int zero = 0;
    if (lbl_805A3340 == v.x && lbl_805A3340 == v.y && lbl_805A3340 == v.z) {
        zero = 1;
    }
    p = &v;
    if (zero) {
        p = &fallback;
    }
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    fn_801ED008(&v, &v);

    if (uniform) {
        const MTX34* m = &matrices[index];
        float t = (m->_00 * m->_00 + m->_10 * m->_10) + m->_20 * m->_20;
        float s = t <= lbl_805A3340 ? lbl_805A3340 : t * fn_801622A0(t);
        register f32 sv = s;
        register f32 zf = lbl_805A3340;
        register f32* vp = &v.x;
        register f32* op = (f32*)out;
        register f32 xy, nx;
        asm { psq_l xy, 0(vp), 0, 0 }
        asm { ps_muls0 xy, xy, sv }
        out->_22 = sv;
        out->_02 = zf;
        asm { ps_merge10 nx, xy, xy }
        out->_12 = zf;
        asm { psq_st nx, 0(op), 0, 0 }
        asm { ps_neg nx, xy }
        asm { psq_st zf, 0x20(op), 0, 0 }
        asm { ps_merge01 nx, nx, xy }
        asm { psq_st nx, 0x10(op), 0, 0 }
    } else {
        float t0 = (matrices[index]._00 * matrices[index]._00 + matrices[index]._10 * matrices[index]._10) + matrices[index]._20 * matrices[index]._20;
        float x = t0 <= lbl_805A3340 ? lbl_805A3340 : t0 * fn_801622A0(t0);
        float t1 = (matrices[index]._01 * matrices[index]._01 + matrices[index]._11 * matrices[index]._11) + matrices[index]._21 * matrices[index]._21;
        float y = t1 <= lbl_805A3340 ? lbl_805A3340 : t1 * fn_801622A0(t1);
        const MTX34* m2 = (const MTX34*)((const char*)matrices + 8);
        float t2 = (m2[index]._00 * m2[index]._00 + matrices[index]._12 * matrices[index]._12) + matrices[index]._22 * matrices[index]._22;
        float z = t2 <= lbl_805A3340 ? lbl_805A3340 : t2 * fn_801622A0(t2);
        register f32 xr = x;
        register f32 yr = y;
        register f32 zero0 = lbl_805A3340;
        register f32* vp = &v.x;
        register f32* op = (f32*)out;
        register f32 tmp, xy, sc, ng;
        asm { psq_l xy, 0(vp), 0, 0 }
        asm { ps_merge00 sc, xr, yr }
        asm { ps_merge10 tmp, xy, xy }
        out->_22 = z;
        asm { ps_neg ng, xy }
        out->_02 = zero0;
        asm { ps_mul tmp, tmp, sc }
        out->_12 = zero0;
        asm { psq_st tmp, 0(op), 0, 0 }
        asm { ps_merge01 tmp, ng, xy }
        asm { psq_st zero0, 0x20(op), 0, 0 }
        asm { ps_mul tmp, tmp, sc }
        asm { psq_st tmp, 0x10(op), 0, 0 }
    }
}
