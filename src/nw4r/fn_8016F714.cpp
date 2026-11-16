#include <types.h>
#include <nw4r/math/math_types.h>

#pragma force_active on

using namespace nw4r::math;

extern "C" f32 fn_801622A0(f32);
extern "C" f64 fn_80400D94(f64);
extern "C" void fn_801ED0B0(const VEC3*, const VEC3*, VEC3*);
extern "C" f32 fn_801ED04C(void*);

extern const f32 lbl_805A2D60;
extern const f32 lbl_805A2D64;
extern const f32 lbl_805A2D68;
extern const f64 lbl_805A2D70;

inline void setVector(VEC3* v, VEC3* a, f32 s, f32 z, f32 y, f32 x,
                      f32* out, f32 reciprocal) {
    *out = reciprocal;
    VEC3Scale(a, a, s);
    v->y = y;
    v->z = z;
    v->x = x;
}

inline void setThirdVector(VEC3* v, VEC3* b, f32 s, f32 z, f32 y, f32 x, f32 value,
                           f32* out, f32 reciprocal, f32* coefficient) {
    *out = reciprocal;
    value *= s;
    VEC3Scale(b, b, s);
    v->x = x;
    v->y = y;
    v->z = z;
    *coefficient = value;
}

extern "C" void fn_8016F714(const MTX34* self, VEC3* out) {
    f32 coefficients[3];
    VEC3 a, b, c, t;
    f32 d;

    a.x = self->m[0][0];
    a.y = self->m[1][0];
    a.z = self->m[2][0];

    d = VEC3LenSq(&a);
    if (d > lbl_805A2D68) {
        f32 s = fn_801622A0(d);

        setVector(&b, &a, s, self->m[2][1], self->m[1][1], self->m[0][1],
                  &out->x, lbl_805A2D64 / s);

        coefficients[0] = VEC3Dot(&a, &b);
        VEC3Scale(&t, &a, coefficients[0]);
        VEC3Sub(&b, &b, &t);

        d = VEC3LenSq(&b);
        if (d > lbl_805A2D68) {
            s = fn_801622A0(d);

            setThirdVector(&c, &b, s, self->m[2][2], self->m[1][2],
                           self->m[0][2], coefficients[0], &out->y,
                           lbl_805A2D64 / s, &coefficients[0]);

            coefficients[2] = VEC3Dot(&b, &c);
            VEC3Scale(&t, &b, coefficients[2]);
            VEC3Sub(&c, &c, &t);

            coefficients[1] = VEC3Dot(&a, &c);
            VEC3Scale(&t, &a, coefficients[1]);
            VEC3Sub(&c, &c, &t);

            d = VEC3LenSq(&c);
            if (d > lbl_805A2D68) {
                out->z = (f32)fn_80400D94(d);
                fn_801ED0B0(&b, &c, &t);

                if (VEC3Dot(&a, &t) < lbl_805A2D60) {
                    out->x = (f32)((f64)out->x * lbl_805A2D70);
                    out->y = (f32)((f64)out->y * lbl_805A2D70);
                    out->z = (f32)((f64)out->z * lbl_805A2D70);
                }
            } else {
                out->z = lbl_805A2D60;
            }
        } else {
            out->y = lbl_805A2D60;

            c.x = self->m[0][2];
            c.y = self->m[1][2];
            c.z = self->m[2][2];

            coefficients[1] = VEC3Dot(&a, &c);
            VEC3Scale(&t, &a, coefficients[1]);
            VEC3Sub(&c, &c, &t);

            d = VEC3LenSq(&c);
            if (d > lbl_805A2D68) {
                out->z = (f32)fn_80400D94(d);
            } else {
                out->z = lbl_805A2D60;
            }
        }
    } else {
        out->x = lbl_805A2D60;

        b.x = self->m[0][1];
        b.y = self->m[1][1];
        b.z = self->m[2][1];

        d = VEC3LenSq(&b);
        if (d > lbl_805A2D68) {
            f32 s = fn_801622A0(d);
            out->y = lbl_805A2D64 / s;
            VEC3Scale(&b, &b, s);

            c.x = self->m[0][2];
            c.y = self->m[1][2];
            c.z = self->m[2][2];

            coefficients[2] = VEC3Dot(&b, &c);
            VEC3Scale(&t, &b, coefficients[2]);
            VEC3Sub(&c, &c, &t);
            out->z = fn_801ED04C(&c);
        } else {
            out->y = lbl_805A2D60;

            c.x = self->m[0][2];
            c.y = self->m[1][2];
            c.z = self->m[2][2];
            out->z = fn_801ED04C(&c);
        }
    }
}
