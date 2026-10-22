#pragma force_active on
typedef float f32;

extern f32 lbl_805A3D80;
extern f32 lbl_805A3D84;

typedef struct {
    f32 f00, f04, f08, f0C;
    f32 f10, f14, f18, f1C;
    f32 f20, f24, f28, f2C;
    f32 f30, f34, f38, f3C;
} Mtx4;

void fn_80287274(Mtx4 *dst, Mtx4 *src) {
    f32 z;
    f32 l, k, j, i, h, g, f, e, d;
    f32 one;
    f32 c, b, a;
    one = lbl_805A3D80;
    a = src->f00;
    b = src->f04;
    c = src->f08;
    d = src->f10;
    e = src->f14;
    f = src->f18;
    g = src->f20;
    h = src->f24;
    i = src->f28;
    j = src->f30;
    k = src->f34;
    l = src->f38;
    dst->f3C = one;
    z = lbl_805A3D84;
    dst->f00 = a;
    dst->f04 = b;
    dst->f08 = c;
    dst->f0C = one;
    dst->f10 = d;
    dst->f14 = e;
    dst->f18 = f;
    dst->f1C = one;
    dst->f20 = g;
    dst->f24 = h;
    dst->f28 = i;
    dst->f2C = one;
    dst->f30 = j;
    dst->f34 = k;
    dst->f38 = l;
    dst->f3C = z;
}
