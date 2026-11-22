#include <nw4r/math/math_types.h>
#pragma force_active on
using namespace nw4r::math;
extern "C" {
extern const float lbl_805A3340;
extern const float lbl_805A3344;
int fn_803F646C(float);
float fn_801622A0(float);
void fn_801ED008(const Vec*, Vec*);
void fn_801ED0B0(const Vec*, const Vec*, Vec*);
}
extern "C" void fn_801A245C(MTX34* out, const MTX34* matrices, int uniform, int unused1, int unused2, int index) {
    VEC3 x;
    VEC3 up(out->_01, out->_11, out->_21);
    VEC3 z(-out->_03, -out->_13, -out->_23);
    VEC3 dz(lbl_805A3340, lbl_805A3340, lbl_805A3344);
    bool invalid = false;
    if (fn_803F646C(z.x) == 1 || fn_803F646C(z.y) == 1 || fn_803F646C(z.z) == 1)
        invalid = true;
    const VEC3* p = invalid ? &dz : &z;
    z = *p;
    bool zero = false;
    if (lbl_805A3340 == z.x && lbl_805A3340 == z.y && lbl_805A3340 == z.z)
        zero = true;
    p = zero ? &dz : &z;
    z = *p;
    VEC3 du(lbl_805A3340, lbl_805A3344, lbl_805A3340);
    invalid = false;
    if (fn_803F646C(up.x) == 1 || fn_803F646C(up.y) == 1 || fn_803F646C(up.z) == 1)
        invalid = true;
    p = invalid ? &du : &up;
    up = *p;
    zero = false;
    if (lbl_805A3340 == up.x && lbl_805A3340 == up.y && lbl_805A3340 == up.z)
        zero = true;
    p = zero ? &du : &up;
    up = *p;
    fn_801ED008(z, z);
    fn_801ED0B0(up, z, x);
    VEC3 dx(lbl_805A3344, lbl_805A3340, lbl_805A3340);
    invalid = false;
    if (fn_803F646C(x.x) == 1 || fn_803F646C(x.y) == 1 || fn_803F646C(x.z) == 1)
        invalid = true;
    p = invalid ? &dx : &x;
    x = *p;
    zero = false;
    if (lbl_805A3340 == x.x && lbl_805A3340 == x.y && lbl_805A3340 == x.z)
        zero = true;
    p = zero ? &dx : &x;
    x = *p;
    fn_801ED008(x, x);
    fn_801ED0B0(z, x, up);
    register MTX34* o = out;
    register VEC3* px = &x;
    register VEC3* pu = &up;
    register VEC3* pz = &z;
    if (uniform) {
        const MTX34& m = matrices[index];
        float v = m._20 * m._20 + (m._00 * m._00 + m._10 * m._10);
        float sc = v <= lbl_805A3340 ? lbl_805A3340 : v * fn_801622A0(v);
        register f32 s = sc, b, c, a, d;
        asm { psq_l a, 0(px), 0, 0 }
        asm { psq_l b, 0(pu), 0, 0 }
        asm { ps_muls0 a, a, s }
        asm { ps_muls0 b, b, s }
        asm { ps_merge00 c, a, b }
        asm { ps_merge11 d, a, b }
        asm { psq_st c, 0(o), 0, 0 }
        asm { psq_st d, 16(o), 0, 0 }
        asm { psq_l a, 0(pz), 0, 0 }
        asm { ps_muls0 a, a, s }
        o->_02 = a;
        asm { ps_merge11 a, a, a }
        o->_12 = a;
        a = x.z;
        a *= sc;
        o->_20 = a;
        a = up.z;
        a *= sc;
        o->_21 = a;
        a = z.z;
        a *= sc;
        o->_22 = a;
    } else {
        float vx = matrices[index]._20 * matrices[index]._20 + (matrices[index]._00 * matrices[index]._00 + matrices[index]._10 * matrices[index]._10);
        float sxv = vx <= lbl_805A3340 ? lbl_805A3340 : vx * fn_801622A0(vx);
        float vy = matrices[index]._21 * matrices[index]._21 + (matrices[index]._01 * matrices[index]._01 + matrices[index]._11 * matrices[index]._11);
        float syv = vy <= lbl_805A3340 ? lbl_805A3340 : vy * fn_801622A0(vy);
        float vz = matrices[index]._22 * matrices[index]._22 + (matrices[index]._02 * matrices[index]._02 + matrices[index]._12 * matrices[index]._12);
        float szv = vz <= lbl_805A3340 ? lbl_805A3340 : vz * fn_801622A0(vz);
        register f32 sz = szv, sx = sxv, sy = syv, b, c, a, d;
        asm { psq_l a, 0(px), 0, 0 }
        asm { psq_l b, 0(pu), 0, 0 }
        asm { ps_muls0 a, a, sx }
        asm { ps_muls0 b, b, sy }
        asm { ps_merge00 c, a, b }
        asm { ps_merge11 d, a, b }
        asm { psq_st c, 0(o), 0, 0 }
        asm { psq_st d, 16(o), 0, 0 }
        asm { psq_l a, 0(pz), 0, 0 }
        asm { ps_muls0 a, a, sz }
        o->_02 = a;
        asm { ps_merge11 a, a, a }
        o->_12 = a;
        a = x.z;
        a *= sxv;
        o->_20 = a;
        a = up.z;
        a *= syv;
        o->_21 = a;
        a = z.z;
        a *= szv;
        o->_22 = a;
    }
}
