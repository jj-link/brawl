#pragma force_active on
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
extern s32 fn_80261274(void *);
extern s32 fn_80261004(u16 *, void *);
extern s32 fn_80261108(s32, void *);
extern s32 fn_80261264(void *);

typedef struct Inner {
    u8 pad0[0x1C];
    u16 w1c;
    u8 pad1e[2];
    u8 b20;
    u8 b21;
} Inner;

typedef struct S {
    u8 pad0[0x1C];
    s32 f1c, f20, f24, f28;
    u8 pad2c[0x3C - 0x2C];
    u16 f3c;
    u16 f3e;
    s32 f40;
} S;

s32 fn_80263180(void *a, u32 x, u32 y) {
    u8 *p = (u8 *)a;
    S *s = (S *)a;
    u16 sp;
    s32 r;
    Inner *in;
    u32 n = s->f3c + 1;
    s32 ret;
    u32 t, w, rem;
    u16 v;
    s32 c;
    u32 row, col;
    in = *(Inner **)(p + 0x19D0);
    s->f3c = n;
    ret = 0;
    if ((u16)n == *(u16 *)(p + 0x1806)) {
        r = fn_80261274(a);
        if (r < 0) return r;
        r = fn_80261004(&sp, a);
        if (sp == 0xFFD9) *(u8 *)(p + 0x1808) = 1;
        if (r < 0) return r;
        if (sp >= 0xFFC0 && (sp < 0xFFD0 || sp > 0xFFD7)) {
            r = fn_80261108(-2, a);
            if (r < 0) return r;
        } else if ((s32)sp != (s32)(s->f3e + 0xFFD0)) {
            return -0x23;
        }
        s->f3e = (s->f3e + 1) & 7;
        c = in->w1c;
        row = (u16)(y / in->b21);
        col = (u16)(x / in->b20);
        s->f1c = 0; s->f20 = 0; s->f24 = 0; s->f28 = 0;
        s->f3c = 0;
        row *= c;
        t = col + row;
        v = t + 1;
        w = (s32)v / c;
        rem = (s32)v % c;
        s->f40 = (rem << 16) + w;
        ret = fn_80261264(a);
    }
    return ret;
}
