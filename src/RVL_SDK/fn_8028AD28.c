#pragma force_active on

typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct Triangle { Vec4 b, a, c; } __attribute__((aligned(16))) Triangle;
extern const unsigned char lbl_8040F958[12];
extern void fn_8028D8C0(Triangle *, void *, void *);

void fn_8028AD28(unsigned char *ctx, void *arg2, const void *arg3,
                 const void *arg4, void *arg5, int i)
{
    Triangle t;
    const unsigned char *base = lbl_8040F958;
    for (i = ctx[2]; i < ctx[2] + ctx[3]; ++i) {
        const Vec4 *a, *b, *c;
        b = (const Vec4 *)((const char *)arg3 + ((const unsigned char *)(i + (unsigned int)base))[1]);
        c = (const Vec4 *)((const char *)arg4 + ((const unsigned char *)(i + (unsigned int)base))[2]);
        a = (const Vec4 *)((const char *)arg3 + base[i]);
        t.a.x = a->x; t.a.y = a->y; t.a.z = a->z; t.a.w = a->w;
        t.b.x = b->x; t.b.y = b->y; t.b.z = b->z; t.b.w = b->w;
        t.c.x = c->x; t.c.y = c->y; t.c.z = c->z; t.c.w = c->w;
        fn_8028D8C0(&t, arg2, arg5);
    }
}