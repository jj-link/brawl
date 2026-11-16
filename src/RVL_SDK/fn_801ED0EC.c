#include <types.h>
#include <revolution/MTX/mtx.h>
#pragma force_active on

extern void fn_801ECFE4(const Vec *a, const Vec *b, Vec *out);
extern void fn_801ED008(const Vec *in, Vec *out);
extern f32 fn_801ED090(const Vec *a, const Vec *b);
extern f32 lbl_805A3798;

static inline void negate(const Vec *in, Vec *out) {
    f32 x = -in->x;
    f32 y = -in->y;
    f32 z = -in->z;
    out->x = x;
    out->y = y;
    out->z = z;
}

void fn_801ED0EC(const Vec *arg0, const Vec *arg1, Vec *arg2) {
    Vec sp20;
    Vec sp14;
    Vec sp8;
    negate(arg0, &sp20);
    negate(arg1, &sp14);
    fn_801ED008(&sp20, &sp20);
    fn_801ED008(&sp14, &sp14);
    fn_801ECFE4(&sp20, &sp14, &sp8);
    if (fn_801ED090(&sp8, &sp8) > lbl_805A3798) {
        fn_801ED008(&sp8, arg2);
    } else {
        *arg2 = sp8;
    }
}
