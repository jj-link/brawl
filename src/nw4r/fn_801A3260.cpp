#include <nw4r/math/math_types.h>
#pragma force_active on
using namespace nw4r::math;

extern "C" float fn_801622A0(float);
extern "C" int fn_803F646C(float);
extern "C" void fn_801ED008(const VEC3*, VEC3*);
extern "C" void fn_801ED0B0(const VEC3*, const VEC3*, VEC3*);
extern "C" const float lbl_805A3340;
extern "C" const float lbl_805A3344;

inline float magnitude(float value) {
    return value <= lbl_805A3340 ? lbl_805A3340 : value * fn_801622A0(value);
}

inline bool vectorInvalid(const VEC3* x) {
    bool invalid = false;
    if (fn_803F646C(x->x) == 1 || fn_803F646C(x->y) == 1 || fn_803F646C(x->z) == 1)
        invalid = true;
    return invalid;
}

extern "C" void fn_801A3260(MTX34* out, const MTX34* matrices, int uniform, int unused1, int unused2, int index) {
    VEC3 z;
    VEC3 y(out->_01, out->_11, out->_21);
    VEC3 x(y.y, -y.x, lbl_805A3340);
    float sy = magnitude(matrices[index]._01 * matrices[index]._01 +
                         matrices[index]._11 * matrices[index]._11 +
                         matrices[index]._21 * matrices[index]._21);
    VEC3 fallback(lbl_805A3344, lbl_805A3340, lbl_805A3340);
    VEC3Scale(&y, &y, FInv(sy));
    const VEC3* selected = vectorInvalid(&x) ? &fallback : &x;
    x = *selected;
    selected = (lbl_805A3340 == x.x && lbl_805A3340 == x.y && lbl_805A3340 == x.z) ? &fallback : &x;
    x = *selected;
    fn_801ED008(&x, &x);
    fn_801ED0B0(&x, &y, &z);
    if (uniform) {
        register VEC3* px = &x;
        register VEC3* py = &y;
        register VEC3* pz = &z;
        register MTX34* dst = out;
        register float scale = sy, b, c, a, d;
        asm { psq_l a, 0(px), 0, 0 }
        asm { psq_l b, 0(py), 0, 0 }
        asm { ps_muls0 a, a, scale }
        asm { ps_muls0 b, b, scale }
        asm { ps_merge00 c, a, b }
        asm { ps_merge11 d, a, b }
        asm { psq_st c, 0(dst), 0, 0 }
        asm { psq_st d, 16(dst), 0, 0 }
        asm { psq_l a, 0(pz), 0, 0 }
        asm { ps_muls0 a, a, scale }
        out->_02 = a;
        asm { ps_merge11 a, a, a }
        out->_12 = a;
        a = x.z;
        a *= sy;
        out->_20 = a;
        a = y.z;
        a *= sy;
        out->_21 = a;
        a = z.z;
        a *= sy;
        out->_22 = a;
    } else {
        float sx = magnitude(matrices[index]._00 * matrices[index]._00 +
                             matrices[index]._10 * matrices[index]._10 +
                             matrices[index]._20 * matrices[index]._20);
        float sz = magnitude(matrices[index]._02 * matrices[index]._02 +
                             matrices[index]._12 * matrices[index]._12 +
                             matrices[index]._22 * matrices[index]._22);
        register VEC3* px = &x;
        register VEC3* py = &y;
        register VEC3* pz = &z;
        register MTX34* dst = out;
        register float scaleZ = sz, scaleX = sx, scaleY = sy, b, c, a, d;
        asm { psq_l a, 0(px), 0, 0 }
        asm { psq_l b, 0(py), 0, 0 }
        asm { ps_muls0 a, a, scaleX }
        asm { ps_muls0 b, b, scaleY }
        asm { ps_merge00 c, a, b }
        asm { ps_merge11 d, a, b }
        asm { psq_st c, 0(dst), 0, 0 }
        asm { psq_st d, 16(dst), 0, 0 }
        asm { psq_l a, 0(pz), 0, 0 }
        asm { ps_muls0 a, a, scaleZ }
        out->_02 = a;
        asm { ps_merge11 a, a, a }
        out->_12 = a;
        a = x.z;
        a *= sx;
        out->_20 = a;
        a = y.z;
        a *= sy;
        out->_21 = a;
        a = z.z;
        a *= sz;
        out->_22 = a;
    }
}
