#include <types.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

struct Obj {
    Matrix m;
    char pad[0x104 - sizeof(Matrix)];
    f32 f104;
    f32 f108;
    f32 f10C;
    f32 f110;
};

struct Pos {
    Vec3f v;
    f32 w;
};

static inline void setv(Vec3f* o, f32 x, f32 y, f32 z) {
    o->m_y = y;
    o->m_x = x;
    o->m_z = z;
}

static inline f32 addf(f32 x, f32 y) {
    return x + y;
}

extern "C" int fn_80019CE4(Obj* self, const Pos* pos) {
    int r = 0;
    Vec3f src;
    setv(&src, pos->v.m_x, pos->v.m_y, pos->v.m_z);
    Vec3f res;
    self->m.mulPos(&src, &res);
    f32 az = (f32)(double)nw4r::math::FAbs(res.m_z);
    f32 ax = (f32)(double)nw4r::math::FAbs(res.m_x);
    f32 a = self->f104;
    f32 b = self->f108;
    f32 c = self->f10C;
    f32 d = self->f110;
    f32 w = pos->w;
    if (!(addf(w * c, ax) >= a * az)) {
        f32 ay = (f32)(double)nw4r::math::FAbs(res.m_y);
        if (!(addf(w * d, ay) >= b * az)) {
            r = 1;
        }
    }
    return r;
}
