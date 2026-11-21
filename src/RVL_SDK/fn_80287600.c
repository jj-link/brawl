#pragma force_active on
#pragma fp_contract on
#include <types.h>
typedef struct Vec4 { f32 x, y, z, w; } Vec4 __attribute__((aligned(16)));
typedef struct Rot { Vec4 c0, c1, c2; } Rot;
typedef struct Xf { Rot r; Vec4 t; } Xf;
extern const f32 lbl_805A3D80;
inline void copyRot(Rot *d, const Rot *s)
{
    f32 x0 = s->c0.x, y0 = s->c0.y, z0 = s->c0.z, w0 = s->c0.w;
    f32 x1 = s->c1.x, y1 = s->c1.y, z1 = s->c1.z, w1 = s->c1.w;
    f32 x2 = s->c2.x, y2 = s->c2.y, z2 = s->c2.z, w2 = s->c2.w;
    d->c0.x = x0; d->c0.y = y0; d->c0.z = z0; d->c0.w = w0;
    d->c1.x = x1; d->c1.y = y1; d->c1.z = z1; d->c1.w = w1;
    d->c2.x = x2; d->c2.y = y2; d->c2.z = z2; d->c2.w = w2;
}
inline void rotInv(Vec4 *o, const Rot *r, const Vec4 *v)
{
    f32 z = v->z, y = v->y, x = v->x;
    o->x = x * r->c0.x + y * r->c0.y + z * r->c0.z;
    o->y = x * r->c1.x + y * r->c1.y + z * r->c1.z;
    o->z = x * r->c2.x + y * r->c2.y + z * r->c2.z;
    o->w = lbl_805A3D80;
}
void fn_80287600(Xf *out, const Xf *a, const Xf *b)
{
    Vec4 h;
    Rot r;
    int i;
    copyRot(&r, &a->r);
    for (i = 0; i < 3; i++) {
        rotInv(&(&out->r.c0)[i], &r, &(&b->r.c0)[i]);
    }
    h.x = b->t.x - a->t.x;
    h.y = b->t.y - a->t.y;
    h.z = b->t.z - a->t.z;
    h.w = b->t.w - a->t.w;
    rotInv(&out->t, &a->r, &h);
}