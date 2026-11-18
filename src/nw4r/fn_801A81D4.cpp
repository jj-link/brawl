#include <nw4r/math/math_types.h>
#pragma force_active on

using namespace nw4r::math;

struct SoraMtxObj {
    float mtx[12];
    char pad30[0x40];
    unsigned int flags;
    VEC3 p74;
    VEC3 p80;
    VEC3 p8C;
    VEC3 p98;
    float fA4;
};

extern "C" void fn_801EC9D8(void* m, VEC3* a, VEC3* b, VEC3* c);
extern "C" void fn_80162384(float* s, float* c, float angle);
extern "C" void fn_801ED008(const VEC3* in, VEC3* out);
extern "C" void fn_801ED0B0(const VEC3* a, const VEC3* b, VEC3* prod);

extern const float lbl_805A3360;
extern const float lbl_805A3368;
extern const float lbl_805A3390;
extern const float lbl_805A3394;

extern "C" void fn_801A81D4(void** arg0) {
    SoraMtxObj* o = (SoraMtxObj*)*arg0;
    if (o->flags & 1) {
        fn_801EC9D8(o, &o->p74, &o->p80, &o->p8C);
    } else if (o->flags & 4) {
        VEC3 d;
        float dz = o->p74.z - o->p8C.z;
        float dx = o->p74.x - o->p8C.x;
        float dy = o->p74.y - o->p8C.y;
        d.x = dx;
        d.z = dz;
        d.y = dy;
        if (lbl_805A3360 == d.x && lbl_805A3360 == d.z) {
            o->mtx[0] = lbl_805A3368;
            o->mtx[1] = lbl_805A3360;
            o->mtx[2] = lbl_805A3360;
            o->mtx[3] = -o->p74.x;
            o->mtx[4] = lbl_805A3360;
            o->mtx[5] = lbl_805A3360;
            o->mtx[8] = lbl_805A3360;
            o->mtx[10] = lbl_805A3360;
            if (d.y <= lbl_805A3360) {
                o->mtx[6] = lbl_805A3368;
                o->mtx[7] = -o->p74.z;
                o->mtx[9] = lbl_805A3390;
                o->mtx[11] = o->p74.y;
            } else {
                o->mtx[6] = lbl_805A3390;
                o->mtx[7] = o->p74.z;
                o->mtx[9] = lbl_805A3368;
                o->mtx[11] = -o->p74.y;
            }
        } else {
            VEC3 n(d.z, lbl_805A3360, -d.x);
            fn_801ED008(&d, &d);
            fn_801ED008(&n, &n);
            VEC3 C;
            fn_801ED0B0(&d, &n, &C);
            float s, c;
            float angle = o->fA4;
            angle = lbl_805A3394 * angle;
            fn_80162384(&s, &c, angle);
            VEC3 row0;
            row0.x = s * C.x + c * n.x;
            row0.y = s * C.y;
            row0.z = s * C.z + c * n.z;
            VEC3 row1;
            row1.x = c * C.x - s * n.x;
            row1.y = c * C.y;
            row1.z = c * C.z - s * n.z;
            o->mtx[0] = row0.x;
            o->mtx[1] = row0.y;
            o->mtx[2] = row0.z;
            o->mtx[3] = -VEC3Dot(&o->p74, &row0);
            o->mtx[4] = row1.x;
            o->mtx[5] = row1.y;
            o->mtx[6] = row1.z;
            o->mtx[7] = -VEC3Dot(&o->p74, &row1);
            o->mtx[8] = d.x;
            o->mtx[9] = d.y;
            o->mtx[10] = d.z;
            o->mtx[11] = -VEC3Dot(&o->p74, &d);
        }
    } else {
        float sx, sy, sz, cx, cy, cz;
        float angleX = o->p98.x;
        angleX = lbl_805A3394 * angleX;
        fn_80162384(&sx, &cx, angleX);
        angleX = o->p98.y;
        angleX = lbl_805A3394 * angleX;
        fn_80162384(&sy, &cy, angleX);
        angleX = o->p98.z;
        angleX = lbl_805A3394 * angleX;
        fn_80162384(&sz, &cz, angleX);
        VEC3 r0;
        r0.x = sz * (sx * sy) + cy * cz;
        r0.y = cx * sz;
        r0.z = sz * (sx * cy) - sy * cz;
        VEC3 r1;
        r1.x = cz * (sx * sy) - cy * sz;
        r1.y = cx * cz;
        r1.z = cz * (sx * cy) + sy * sz;
        VEC3 r2;
        r2.x = cx * sy;
        r2.y = -sx;
        r2.z = cx * cy;
        o->mtx[0] = r0.x;
        o->mtx[1] = r0.y;
        o->mtx[2] = r0.z;
        o->mtx[3] = -VEC3Dot(&o->p74, &r0);
        o->mtx[4] = r1.x;
        o->mtx[5] = r1.y;
        o->mtx[6] = r1.z;
        o->mtx[7] = -VEC3Dot(&o->p74, &r1);
        o->mtx[8] = r2.x;
        o->mtx[9] = r2.y;
        o->mtx[10] = r2.z;
        o->mtx[11] = -VEC3Dot(&o->p74, &r2);
    }
    o->flags |= 8;
}
