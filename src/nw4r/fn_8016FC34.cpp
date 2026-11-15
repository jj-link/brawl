#include <math.h>
#include <nw4r/math/math_types.h>
#pragma force_active on

using nw4r::math::MTX34;
using nw4r::math::VEC3;
using nw4r::math::VEC3Add;
using nw4r::math::VEC3Scale;

extern "C" const float lbl_805A2D78;
extern "C" const float lbl_805A2D7C;
extern "C" const float lbl_805A2D80;
extern "C" const float lbl_805A2D84;
extern "C" const float lbl_805A2D88;
extern "C" const float lbl_805A2D8C;
extern "C" const float lbl_805A2D90;

extern "C" void fn_801629AC(MTX34* m, float x, float y, float z);
extern "C" void fn_801ECD70(MTX34* m, VEC3* in, VEC3* out);
extern "C" void fn_801EC1B8(MTX34* a, MTX34* b, MTX34* out);

struct FcObj {
    char pad0[0x66];
    signed char f66;
    char pad67;
    float f68;
    float f6C;
    float f70;
    float f74;
    char pad78[0x4];
    float f7C;
    float f80;
    float f84;
    float f88;
    float f8C;
    char pad90[0x5C];
    unsigned int seed;
};

extern "C" void fn_8016FC34(void* unused0, VEC3* out, FcObj* obj, void* unused3,
                            const VEC3* vA, const VEC3* vB, const VEC3* vC)
{
    if (lbl_805A2D78 != obj->f68) {
        VEC3Scale(out, vB, obj->f68);
    } else {
        out->x = lbl_805A2D78;
        out->y = lbl_805A2D78;
        out->z = lbl_805A2D78;
    }

    if (lbl_805A2D78 != obj->f6C) {
        VEC3 tmp;
        VEC3Scale(&tmp, vC, obj->f6C);
        VEC3Add(out, out, &tmp);
    }

    if (lbl_805A2D78 != obj->f70) {
        float cA1, a2, cA2, sA1, sA2, sA3, a1, a3;
        unsigned int s1 = obj->seed * 0x343FD;
        s1 += 0x269EC3;
        obj->seed = s1;
        a1 = lbl_805A2D80 * (lbl_805A2D84 * ((float)(s1 >> 16) / lbl_805A2D7C));
        unsigned int s2 = s1 * 0x343FD;
        s2 += 0x269EC3;
        obj->seed = s2;
        a2 = lbl_805A2D80 * (lbl_805A2D84 * ((float)(s2 >> 16) / lbl_805A2D7C));
        unsigned int s3 = s2 * 0x343FD;
        s3 += 0x269EC3;
        obj->seed = s3;
        a3 = lbl_805A2D80 * (lbl_805A2D84 * ((float)(s3 >> 16) / lbl_805A2D7C));
        sA1 = (float)sin(a1);
        cA1 = (float)cos(a1);
        sA2 = (float)sin(a2);
        cA2 = (float)cos(a2);
        sA3 = (float)sin(a3);
        float cA3 = (float)cos(a3);
        out->x += obj->f70 * (cA3 * (cA1 * sA2) + sA1 * sA3);
        out->y += obj->f70 * (sA3 * (cA1 * sA2) - sA1 * cA3);
        out->z += cA2 * (obj->f70 * cA1);
    }

    if (lbl_805A2D78 != obj->f74) {
        out->x += vA->x * obj->f74;
        out->y += vA->y * obj->f74;
        out->z += vA->z * obj->f74;
    }

    if (lbl_805A2D78 != obj->f7C) {
        if (lbl_805A2D78 == obj->f80) {
            MTX34 m;
            float x, y, z;
            z = obj->f8C;
            y = obj->f88;
            x = obj->f84;
            fn_801629AC(&m, lbl_805A2D88 * x, lbl_805A2D88 * y,
                        lbl_805A2D88 * z);
            VEC3 v(lbl_805A2D78, lbl_805A2D8C, lbl_805A2D78);
            fn_801ECD70(&m, &v, &v);
            out->x += obj->f7C * v.x;
            out->y += obj->f7C * v.y;
            out->z += obj->f7C * v.z;
        } else {
            unsigned int s1 = obj->seed * 0x343FD;
            s1 += 0x269EC3;
            obj->seed = s1;
            float x, y;
            float u1 = (float)(s1 >> 16) / lbl_805A2D7C;
            float angle = lbl_805A2D84 * u1;
            float angle2 = lbl_805A2D80 * angle;
            unsigned int s2 = s1 * 0x343FD;
            s2 += 0x269EC3;
            obj->seed = s2;
            float u2 = (float)(s2 >> 16) / lbl_805A2D7C;
            MTX34 m1;
            x = obj->f80 * u2;
            y = lbl_805A2D88 * angle2;
            x = lbl_805A2D88 * x;
            fn_801629AC(&m1, x, y, lbl_805A2D78);
            MTX34 m2;
            float rx, ry, rz;
            rz = obj->f8C;
            ry = obj->f88;
            rx = obj->f84;
            fn_801629AC(&m2, lbl_805A2D88 * rx, lbl_805A2D88 * ry,
                        lbl_805A2D88 * rz);
            fn_801EC1B8(&m2, &m1, &m1);
            out->x += m1.m[0][1] * obj->f7C;
            out->y += m1.m[1][1] * obj->f7C;
            out->z += m1.m[2][1] * obj->f7C;
        }
    }

    signed char b = obj->f66;
    if (b != 0) {
        unsigned int s = obj->seed * 0x343FD;
        s += 0x269EC3;
        obj->seed = s;
        float u = (float)(s >> 16) / lbl_805A2D7C;
        float t = lbl_805A2D8C -
                  (lbl_805A2D90 * (float)b) * (lbl_805A2D80 * u - lbl_805A2D8C);
        out->x *= t;
        out->y *= t;
        out->z *= t;
    }
}
