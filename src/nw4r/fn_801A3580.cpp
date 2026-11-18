#include <nw4r/math/math_types.h>
#pragma force_active on

using namespace nw4r::math;

extern "C" {
float fn_801622A0(float);
int fn_803F646C(float);
void fn_801ED008(const VEC3*, VEC3*);
void fn_801ED0B0(const VEC3*, const VEC3*, VEC3*);
extern const float lbl_805A3340;
extern const float lbl_805A3344;
}

extern "C" void fn_801A3580(MTX34* out, const MTX34* matrices,
                            int uniform, int unused1, int unused2, int index) {
    VEC3 x;
    VEC3 y(out->_01, out->_11, out->_21);
    VEC3 z(-out->_03, -out->_13, -out->_23);

    float sq = matrices[index]._01 * matrices[index]._01 +
               matrices[index]._11 * matrices[index]._11 +
               matrices[index]._21 * matrices[index]._21;
    float sy = sq <= lbl_805A3340 ? lbl_805A3340 : sq * fn_801622A0(sq);
    VEC3Scale(&y, &y, FInv(sy));

    VEC3 defaultZ(lbl_805A3340, lbl_805A3340, lbl_805A3344);
    bool bad = fn_803F646C(z.x) == 1 ||
               fn_803F646C(z.y) == 1 ||
               fn_803F646C(z.z) == 1;
    const VEC3* selectedZ = &z;
    if (bad)
        selectedZ = &defaultZ;
    z.x = selectedZ->x;
    z.y = selectedZ->y;
    z.z = selectedZ->z;
    z = lbl_805A3340 == z.x && lbl_805A3340 == z.y && lbl_805A3340 == z.z
            ? defaultZ : z;

    VEC3 defaultY(lbl_805A3340, lbl_805A3344, lbl_805A3340);
    bad = fn_803F646C(y.x) == 1 ||
          fn_803F646C(y.y) == 1 ||
          fn_803F646C(y.z) == 1;
    const VEC3* selectedY = &y;
    if (bad)
        selectedY = &defaultY;
    y.x = selectedY->x;
    y.y = selectedY->y;
    y.z = selectedY->z;
    y = lbl_805A3340 == y.x && lbl_805A3340 == y.y && lbl_805A3340 == y.z
            ? defaultY : y;

    fn_801ED0B0(&y, &z, &x);

    VEC3 defaultX(lbl_805A3344, lbl_805A3340, lbl_805A3340);
    bad = fn_803F646C(x.x) == 1 ||
          fn_803F646C(x.y) == 1 ||
          fn_803F646C(x.z) == 1;
    const VEC3* selectedX = &x;
    if (bad)
        selectedX = &defaultX;
    x.x = selectedX->x;
    x.y = selectedX->y;
    x.z = selectedX->z;
    x = lbl_805A3340 == x.x && lbl_805A3340 == x.y && lbl_805A3340 == x.z
            ? defaultX : x;

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
        float sqX = matrices[index]._00 * matrices[index]._00 +
                    matrices[index]._10 * matrices[index]._10 +
                    matrices[index]._20 * matrices[index]._20;
        float sx = sqX <= lbl_805A3340 ? lbl_805A3340 : sqX * fn_801622A0(sqX);
        float sqZ = matrices[index]._02 * matrices[index]._02 +
                    matrices[index]._12 * matrices[index]._12 +
                    matrices[index]._22 * matrices[index]._22;
        float sz = sqZ <= lbl_805A3340 ? lbl_805A3340 : sqZ * fn_801622A0(sqZ);

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
