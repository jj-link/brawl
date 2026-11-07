#pragma force_active on
typedef float f32;
#pragma fp_contract on
extern const f32 lbl_805A46B8;
extern const f32 lbl_805A46CC;
extern const f32 lbl_805A46D8;

struct In { int a; int b; char p[0x18]; f32 v0[4]; char q[0xa0-0x30]; f32 v1[4]; char r[0x130-0xb0]; f32 v2[4]; };
struct Out { f32 a[4]; f32 b[4]; f32 c; f32 d; };

extern "C" void fn_8031AC7C(In* s, const f32* q, Out* o) {
    f32 z, y, x, w;
    w = q[3];
    x = q[0];
    y = q[1];
    z = q[2];
    o->c = w;
    o->a[0] = x;
    o->a[1] = y;
    o->a[2] = z;
    o->a[3] = w;
    if (s->a == 1) {
        o->b[0] = s->v0[0];
        o->b[1] = s->v0[1];
        o->b[2] = s->v0[2];
        o->b[3] = s->v0[3];
        o->d = lbl_805A46CC;
        return;
    }
    if (s->b == 1) {
        o->b[0] = w * x + s->v1[0];
        o->b[1] = w * y + s->v1[1];
        o->b[2] = w * z + s->v1[2];
        o->b[3] = w * w + s->v1[3];
        o->d = lbl_805A46B8;
        return;
    }
    o->b[0] = s->v2[0];
    o->b[1] = s->v2[1];
    o->b[2] = s->v2[2];
    o->b[3] = s->v2[3];
    o->d = lbl_805A46D8;
}
