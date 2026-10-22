#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Ctx {
    u16 f0;
    char p2[4];
    u8 f6;
    char p7[9];
    int f10;
    char p14[8];
    int f1c;
    u8 f20;
    u8 f21;
    char p22[14];
    int f30;
} Ctx;
typedef struct Buf { int p0; int p4; int f8; } Buf;
typedef struct Ent { int a; int b; u32 c; int d; int e; } Ent;
extern Ent lbl_804169B0[];
extern void fn_803A976C(int, int, int);
extern int fn_803AFD48(Ctx *, int, Buf **);
extern void fn_803AFE4C(Ctx *, Buf *);
extern int fn_803B0140(Ctx *);
extern int fn_803B89DC(Ctx *, u16, u16);
extern int fn_803B932C(Ctx *, int, u32);
extern int fn_803B98C4(Ctx *, int, u32);
extern int fn_803C0440(Ctx *, int, int, int, u16, u32 *, int);

int fn_803B7F1C(Ctx *c) {
    u32 spC;
    Buf *sp8;
    int r;
    int base;
    int i;
    int t = c->f1c;
    int a = c->f10;
    u32 v = lbl_804169B0[t].c;
    switch (t) {
    case 0:
        if (v > 0xFFF) r = 0x10;
        else r = fn_803B89DC(c, a, v);
        break;
    case 1:
        if (v > 0xFFFF) r = 0x10;
        else r = fn_803B932C(c, a, v);
        break;
    case 2:
        if (v > 0xFFFFFFF) r = 0x10;
        else r = fn_803B98C4(c, a, v);
        break;
    default:
        r = 0xF;
    }
    if (r != 0) return r;
    r = fn_803B0140(c);
    if (r != 0) return r;
    r = fn_803AFD48(c, -1, &sp8);
    if (r != 0) return r;
    fn_803A976C(sp8->f8, 0, c->f0);
    base = c->f30 + ((c->f10 - 2) << c->f21);
    for (i = 0; (u32)i < c->f6; i++) {
        r = fn_803C0440(c, sp8->f8, base + i, 0, c->f0, &spC, 0);
        if (r != 0) {
            fn_803AFE4C(c, sp8);
            return r;
        }
        if (spC != c->f0) {
            fn_803AFE4C(c, sp8);
            return 0x11;
        }
    }
    fn_803AFE4C(c, sp8);
    return 0;
}
