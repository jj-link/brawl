#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Rec {
    u16 s0;
    u8 pad0[0x20A - 2];
    u8 b20A, b20B, b20C;
    u8 pad1[0x21C - 0x20D];
    u8 f21C;
    u8 pad2[0x224 - 0x21D];
    u16 h224, h226;
    u32 w228;
    u8 *own;
    u32 w230;
    u32 w234;
    u32 w238;
    u16 h23C;
    u8 pad3[0x240 - 0x23E];
} Rec;
typedef struct Sub {
    u8 pad[0x15E0];
    int a;
    int b;
} Sub;
typedef struct Obj {
    u8 pad0[8];
    Sub *p8;
    u32 pC;
    u32 n10;
    u32 f14;
    u8 b18, b19, b1a, b1b;
    u8 buf1c[0x208];
    u16 h224, h226;
    u32 w228;
    u8 b22c;
    u8 b22d[0xd];
    u8 b23a;
    u8 pad[0x444 - 0x23b];
    u8 b444[0x208];
    u8 b64c[0x1a];
    u16 h666;
} Obj;
typedef struct Nt { u8 pad[0x3c]; u32 f3c; } Nt;
extern Nt lbl_8053B248;
extern void fn_803A9884(void *, void *);
extern void fn_803A9A80(void *, void *);
extern int fn_803A9BB4(void *, void *, int);
extern void fn_803AA01C(void *, void *);
extern int fn_803B2F1C(void *, void *, u32, void *, int, int, int *, u32 *);
extern void fn_803B847C(void *, void *, void *, void *);
extern void fn_803BBFF8(void *, void *);
extern void fn_803BEE24(void *, void *);
extern void fn_803BEF50(void *, void *);

int fn_803B161C(Obj *o) {
    Rec r;
    u8 sp38[56];
    u8 sp28[16];
    u8 sp18[16];
    Rec *sp10;
    int spC;
    u32 sp8;
    int r3;
    u32 n;
    u8 *cursor;
    u8 *e;
    u32 a;
    u16 c;
    u8 *base;
    u32 fl;
    spC = 0;
    sp8 = 0;
    if ((o->f14 & 1) == 1)
        r3 = fn_803A9BB4(sp18, o->buf1c, 1);
    else
        r3 = fn_803A9BB4(sp18, o->b444, 2);
    if (r3 != 0) return r3;
    fn_803A9A80(sp18, o->buf1c);
    goto cond;
body:
    n = o->n10;
    if (n >= 0xF423F) return 10;
    r.w234 = o->pC;
    fn_803B847C(sp38, sp28, o->p8, &r.w234);
    r3 = fn_803B2F1C(sp38, &r, o->n10, sp18, o->b1b, 0, &spC, &sp8);
    if (r3 != 0) return r3;
    o->n10 = sp8 + 1;
    if (sp8 + 0xFFF10000 == 0x423F) return 3;
    goto after;
cond:
    if (sp8 < 0xF423F) goto body;
after:
    fn_803A9884(o->b22d, (u8 *)&r + 0x20E);
    if ((o->f14 & 2) == 2) fn_803BEF50(o->b64c, o->b22d);
    if (r.s0 != 0) {
        if ((lbl_8053B248.f3c & 2) == 2) {
            lbl_8053B248.f3c = (lbl_8053B248.f3c & ~3) | 1;
            fn_803BEE24(&o->b23a, &r);
            lbl_8053B248.f3c = (lbl_8053B248.f3c & ~3) | 2;
        } else
            fn_803BEE24(&o->b23a, &r);
        if ((o->f14 & 2) == 2) fn_803AA01C(&o->h666, &r);
    } else {
        o->b23a = 0;
        if ((o->f14 & 2) == 2) o->h666 = 0;
    }
    sp10 = 0;
    if ((r.f21C & 0x10) && o->p8->b != 0) {
        int i;
        base = r.own;
        a = r.w238;
        c = r.h23C;
        e = base + 0xE40;
        sp10 = 0;
        cursor = base;
        for (i = 0; i < 3; i++, cursor += 0x280, e += 0x280) {
            fl = *(u32 *)(cursor + 0xE00);
            if ((fl & 1) && (fl & 2) && base == *(u8 **)(cursor + 0x106c) && a == *(u32 *)(cursor + 0x1078) && c == *(u16 *)(cursor + 0x107c))
                sp10 = (Rec *)e;
        }
    } else if (!(r.f21C & 0x10) && !(r.f21C & 8) && o->p8->a != 0) {
        fn_803BBFF8(&r, &sp10);
    }
    if (sp10 == 0) sp10 = &r;
    o->w228 = sp10->w228;
    o->h224 = sp10->h224;
    o->h226 = sp10->h226;
    o->b22c = sp10->f21C;
    if (o->b22c == 0) o->b22c = 0x40;
    o->b18 = sp10->b20A;
    o->b19 = sp10->b20B;
    o->b1a = sp10->b20C;
    return 0;
}
