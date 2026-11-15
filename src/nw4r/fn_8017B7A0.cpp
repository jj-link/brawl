#include <types.h>
#include <nw4r/math/math_types.h>
#include <revolution/GX/GXVert.h>
#pragma force_active on

using namespace nw4r::math;

extern "C" {
void fn_801ED0B0(const VEC3*, const VEC3*, VEC3*);
void fn_801ECD70(const MTX34*, s32, VEC3*);
void fn_801EC1B8(const MTX34*, const MTX34*, MTX34*, f32, f32, f32, f32, f32);
f32 fn_801622A0(f32);
f32 fn_801622C4(f32);
f32 fn_8016232C(f32);
extern const f32 lbl_805A303C;
extern const f32 lbl_805A3048;
extern const f32 lbl_805A304C;
extern const f32 lbl_805A3050;
extern const f32 lbl_805A3054;
}

static inline VEC3& divBy(VEC3& v, f32 x) {
    return v *= (lbl_805A303C / x);
}

extern "C" void fn_8017B7A0(void* unused, void* a1, u32 flags, void* obj,
                            void (*fn)(VEC3*, void*, void*), const VEC3* vecA,
                            s32 idx1, s32 idx2, f32 farg0, f32 farg1) {
    MTX34 m3, m1, m2;
    VEC3 sp44, pA, pB, sp20, sp14, pos;
    f32 f29;

    if (obj == NULL) {
        void* p = *(void**)a1;
        void* node = *(void**)((u8*)p + 0x3C);
        while (node != NULL && *(s32*)((u8*)node + 0xC) != 1) {
            u16 off = *(u16*)((u8*)p + 0x42);
            node = *(void**)((u8*)node + off);
            while (node != NULL && *(s32*)((u8*)node + 0xC) != 1) {
                node = *(void**)((u8*)node + off);
            }
        }
        obj = node;
    }

    fn(&sp44, a1, obj);
    VEC3* pa = &sp44;
    if (!(flags & 2)) {
        fn_801ED0B0(pa, (const VEC3*)((u8*)obj + 0xCC), &sp14);
    } else {
        fn_801ED0B0(pa, (const VEC3*)((u8*)a1 + 0xC8), &sp14);
    }

    s32 ok;
    f29 = VEC3Dot(&sp14, &sp14);
    if (f29 < lbl_805A3048) {
        ok = 0;
    } else {
        f32 t;
        if (f29 <= lbl_805A304C) {
            t = lbl_805A304C;
        } else {
            t = f29 * fn_801622A0(f29);
        }
        divBy(sp14, t);
        ok = 1;
    }
    if (ok == 0) {
        sp14 = *(VEC3*)((u8*)a1 + 0xBC);
    }

    fn_801ED0B0(&sp14, pa, &sp20);
    f29 = VEC3Dot(&sp20, &sp20);
    if (!(f29 < lbl_805A3048)) {
        f32 t;
        if (f29 <= lbl_805A304C) {
            t = lbl_805A304C;
        } else {
            t = f29 * fn_801622A0(f29);
        }
        divBy(sp20, t);
    }

    *(VEC3*)((u8*)obj + 0xCC) = sp20;

    f32 a23 = vecA->z, a22 = sp20.z, a21 = sp44.z, a20 = sp14.z;
    f32 a13 = vecA->y, a12 = sp20.y, a11 = sp44.y, a10 = sp14.y;
    f32 a03 = vecA->x, a02 = sp20.x, a01 = sp44.x, a00 = sp14.x;
    m1.m[0][1] = a01; m1.m[0][0] = a00; m1.m[0][2] = a02; m1.m[0][3] = a03;
    m1.m[1][0] = a10; m1.m[1][1] = a11; m1.m[1][2] = a12; m1.m[1][3] = a13;
    m1.m[2][0] = a20; m1.m[2][1] = a21; m1.m[2][2] = a22; m1.m[2][3] = a23;

    pos.x = *(f32*)((u8*)obj + 0x40);
    pos.y = *(f32*)((u8*)obj + 0x44);
    pos.z = *(f32*)((u8*)obj + 0x48);
    {
        u8 b;
        b = *(u8*)((u8*)obj + 0x9A);
        if (b != 0) {
            pos.x = pos.x + lbl_805A3050 * (f32)b;
        }
        b = *(u8*)((u8*)obj + 0x9B);
        if (b != 0) {
            pos.y = pos.y + lbl_805A3050 * (f32)b;
        }
        b = *(u8*)((u8*)obj + 0x9C);
        if (b != 0) {
            pos.z = pos.z + lbl_805A3050 * (f32)b;
        }
    }

    {
        u8* S = *(u8**)((u8*)obj + 0xC8);
        f32 y = pos.y + *(f32*)(S + 0x64);
        f32 x = pos.x + *(f32*)(S + 0x60);
        f32 z = pos.z + *(f32*)(S + 0x68);
        pos.y = y;
        pos.x = x;
        pos.z = z;
        f32 f6 = *(f32*)((u8*)obj + 0x30) * *(f32*)((u8*)obj + 0x38);
        f32 f28 = f6 * *(f32*)(S + 0x58);
        f29 = f28 * fn_8016232C(lbl_805A3054 * pos.y);
        f32 s = f28 * fn_801622C4(lbl_805A3054 * (f32)(double)pos.y);
        f32 omc = farg0 - f29 * farg0;

        m2.m[0][0] = f29;
        m2.m[0][1] = lbl_805A304C;
        m2.m[0][2] = -s;
        m2.m[0][3] = omc;
        m2.m[1][0] = lbl_805A304C;
        m2.m[1][1] = lbl_805A303C;
        m2.m[1][2] = lbl_805A304C;
        m2.m[1][3] = lbl_805A304C;
        m2.m[2][0] = s;
        m2.m[2][1] = lbl_805A304C;
        m2.m[2][2] = f29;
        m2.m[2][3] = -s * farg0;

        fn_801EC1B8(&m1, &m2, &m3, lbl_805A303C, omc, -s, lbl_805A304C, s);
    }

    fn_801ECD70(&m3, idx1, &pA);
    fn_801ECD70(&m3, idx2, &pB);

    GXPosition3f32(pA.x, pA.y, pA.z);
    if (flags & 1) {
        GXTexCoord2f32(lbl_805A303C, farg1);
    }
    GXPosition3f32(pB.x, pB.y, pB.z);
    if (flags & 1) {
        GXTexCoord2f32(lbl_805A304C, farg1);
    }
}
