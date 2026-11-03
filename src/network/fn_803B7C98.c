#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Ctx {
    u16 f0, f2;
    char pad4[0x16];
    u8 f1a;
    char pad1b;
    int f1c;
    char pad20[12];
    u32 f2c;
} Ctx;
typedef struct Buf { int p0, p4, f8; } Buf;
typedef struct Ent { u32 a, b, c, d, e; } Ent;
extern Ent lbl_804169B0[];
extern void fn_803A976C(int, int, int);
extern int fn_803AFCD4(Ctx *, int, Buf **);
extern void fn_803AFDBC(Ctx *, Buf *);
extern int fn_803B0084(Ctx *, int, u32);
extern int fn_803B0140(Ctx *);
extern int fn_803B89DC(Ctx *, u16, u16);
extern int fn_803B932C(Ctx *, int, u32);
extern int fn_803B98C4(Ctx *, int, u32);

int fn_803B7C98(Ctx *c) {
    Buf *buf;
    int r;
    u32 i;
    int t;
    u32 v;
    if (!c) return 10;
    if (c->f1c != 0 && c->f1c != 1 && c->f1c != 2) return 15;
    r = fn_803AFCD4(c, -1, &buf);
    if (r != 0) return r;
    fn_803A976C(buf->f8, 0, c->f0);
    for (i = c->f2; i < c->f2c; i++) {
        r = fn_803B0084(c, buf->f8, i);
        if (r != 0) {
            fn_803AFDBC(c, buf);
            return r;
        }
    }
    fn_803AFDBC(c, buf);
    t = c->f1c;
    v = c->f1a | lbl_804169B0[t].d;
    switch (t) {
    case 0:
        if (v > 0xfff) r = 16;
        else r = fn_803B89DC(c, 0, v);
        break;
    case 1:
        if (v > 0xffff) r = 16;
        else r = fn_803B932C(c, 0, v);
        break;
    case 2:
        if (v > 0xfffffff) r = 16;
        else r = fn_803B98C4(c, 0, v);
        break;
    default:
        r = 15;
    }
    if (r != 0) return r;
    t = c->f1c;
    v = lbl_804169B0[t].e;
    switch (t) {
    case 0:
        if (v > 0xfff) r = 16;
        else r = fn_803B89DC(c, 1, v);
        break;
    case 1:
        if (v > 0xffff) r = 16;
        else r = fn_803B932C(c, 1, v);
        break;
    case 2:
        if (v > 0xfffffff) r = 16;
        else r = fn_803B98C4(c, 1, v);
        break;
    default:
        r = 15;
    }
    if (r != 0) return r;
    r = fn_803B0140(c);
    return r & ((-r | r) >> 31);
}