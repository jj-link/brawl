#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct S {
    u8 f0;
    u8 pad1;
    u8 f2;
    u8 pad3[9];
    u8 fC;
    u8 fD;
    u8 pad_e;
    u8 fF;
    u8 pad10[0x4F];
    u8 f5F;
    u8 pad60[8];
    u8 f68;
    u8 pad69[3];
    u8 *f6C;
    u8 pad70[0x18];
    u32 f88;
    void (*f8C)(int, int);
    void (*f90)(int, int);
} S;

extern u8 lbl_8052D5A8[];
extern char lbl_8048416C[];
extern char lbl_80484198[];
extern void fn_802319E4(u32, const char *);
extern void fn_80231A14(u32, const char *, int, int);
extern void fn_802519F4(S *);
extern int fn_80251C1C(S *, u8, u8, u8);
extern void fn_8025648C(S *);
extern void fn_802564E4(u8 *);

void fn_802516E4(S *s, int a)
{
    int r = 0;
    u8 *p;
    u8 t = s->f2;
    p = s->f6C;
    if (t == 1 && s->fC != 0) {
        if (lbl_8052D5A8[0x414] >= 4U) {
            fn_802319E4(0x90003, lbl_8048416C);
        }
        fn_8025648C(s);
        r = 0;
        s->f68 = 0;
        if (p != 0) {
            u8 *q = p + s->fD;
            q[0x24] = 0;
            fn_802564E4(p);
            s->f6C = (u8 *)r;
        }
        s->fD &= 0xFE;
        return;
    }
    if (t != 3 && t != 0) {
        u8 x = s->fF | 0x10;
        u8 a4 = s->f5F;
        u8 y = a4 & ~0xB;
        s->fF = x;
        s->f5F = y;
        r = fn_80251C1C(s, a4, y, x);
        if (s->f88 & 0x8000) {
            r |= 0x8000;
        }
    }
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_80231A14(0x90003, lbl_80484198, s->f2, r);
    }
    if (s->f8C != 0 && r != 0) {
        s->f8C(r, s->f0);
    }
    if (s->f90 != 0) {
        s->f90(a, s->f0);
    }
    s->f68 = 0;
    fn_802519F4(s);
}
