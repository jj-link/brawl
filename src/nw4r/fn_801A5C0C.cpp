#pragma force_active on
struct Src {
    int flags, pad;
    int a, b, c, d, e, f, g, h, i, j, k;
    int x, y, z;
};
struct Dst {
    int a, b, e, k, g, h, i, d, j, f, c;
    int x, y, z;
};
extern "C" void fn_801A5C0C(Dst* dst, Src* src, int n) {
    int t;
    t = src->a; if (t) dst->a = t + n * 0x104; else dst->a = 0;
    t = src->b; if (t) dst->b = t + n * 0x64; else dst->b = 0;
    t = src->c; if (t) dst->c = t + n * 0x248; else dst->c = 0;
    t = src->d; if (t) dst->d = t + n * 0x28; else dst->d = 0;
    t = src->e; if (t) dst->e = t + n * 8; else dst->e = 0;
    t = src->f; if (t) dst->f = t + n * 0xc; else dst->f = 0;
    t = src->g; if (t) dst->g = t + n * 0x20; else dst->g = 0;
    t = src->h; if (t) dst->h = t + n * 0x80; else dst->h = 0;
    t = src->i; if (t) dst->i = t + n * 0x40; else dst->i = 0;
    t = src->j; if (t) dst->j = t + n * 0xa0; else dst->j = 0;
    t = src->k; if (t) dst->k = t + n * 0x200; else dst->k = 0;
    if (src->flags & 1) {
        dst->x = 0; dst->y = 0; dst->z = 0;
        return;
    }
    dst->x = src->x; dst->y = src->y; dst->z = src->z;
}