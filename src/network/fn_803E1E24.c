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
extern Ent lbl_8041B0E0[];
extern void fn_803D634C(int, int, int);
extern int fn_803DA3DC(Ctx *, int, Buf **, int *);
extern void fn_803DA4CC(Ctx *, Buf *);
extern int fn_803DA794(Ctx *, int, u32);
extern int PFCACHE_FlushFATCache(Ctx *);
extern int fn_803E25FC(Ctx *, u16, u16);
extern int fn_803E2DF0(Ctx *, int, u32);
extern int fn_803E3244(Ctx *, int, u32);

int fn_803E1E24(Ctx *c) {
    Buf *buf;
    int unused;
    int r;
    u32 i;
    int t;
    u32 v;
    r = fn_803DA3DC(c, -1, &buf, &unused);
    if (r != 0) return r;
    fn_803D634C(buf->f8, 0, c->f0);
    for (i = c->f2; i < c->f2c; i++) {
        r = fn_803DA794(c, buf->f8, i);
        if (r != 0) {
            fn_803DA4CC(c, buf);
            return r;
        }
    }
    fn_803DA4CC(c, buf);
    t = c->f1c;
    v = c->f1a | lbl_8041B0E0[t].d;
    switch (t) {
    case 0:
        if (v > 0xfff) r = 16;
        else r = fn_803E25FC(c, 0, v);
        break;
    case 1:
        if (v > 0xffff) r = 16;
        else r = fn_803E2DF0(c, 0, v);
        break;
    case 2:
        if (v > 0xfffffff) r = 16;
        else r = fn_803E3244(c, 0, v);
        break;
    default:
        r = 15;
    }
    if (r != 0) return r;
    t = c->f1c;
    v = lbl_8041B0E0[t].e;
    switch (t) {
    case 0:
        if (v > 0xfff) r = 16;
        else r = fn_803E25FC(c, 1, v);
        break;
    case 1:
        if (v > 0xffff) r = 16;
        else r = fn_803E2DF0(c, 1, v);
        break;
    case 2:
        if (v > 0xfffffff) r = 16;
        else r = fn_803E3244(c, 1, v);
        break;
    default:
        r = 15;
    }
    if (r != 0) return r;
    r = PFCACHE_FlushFATCache(c);
    return r & ((-r | r) >> 31);
}