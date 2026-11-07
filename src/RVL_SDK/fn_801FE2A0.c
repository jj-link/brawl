#pragma global_optimizer off
#include <revolution/OS/OSError.h>
#pragma force_active on
extern char lbl_80477190[];
extern unsigned char lbl_805A09B8;
extern int lbl_805A09BC, lbl_805A09C0;
extern unsigned int lbl_805A09D4;
extern int lbl_8059EAF8;
extern unsigned int fn_801FC774(unsigned int, void *);
extern int fn_80212C08(int, int, void *, int, int, int, void (*)(void), void *);
typedef struct { int a, b; unsigned char c; unsigned int magic, id; char pad[12]; } Context;
extern Context lbl_804E46A0[4];

static inline Context *newContext(int arg, char *base, int one) {
    int idx = lbl_805A09C0;
    if ((unsigned int)(lbl_804E46A0[idx].c != 0) == 1) {
        OSReport(base + 0x240, idx);
        OSReport(base + 0x278);
        for (;;) {}
    }
    if (lbl_804E46A0[idx].magic != 0xFEEBDAED) {
        OSReport(base + 0x2a8);
        for (;;) {}
    }
    lbl_804E46A0[idx].a = arg;
    lbl_804E46A0[idx].b = one;
    lbl_804E46A0[idx].c = one;
    lbl_805A09C0 = idx + 1;
    if (lbl_805A09C0 >= 4) lbl_805A09C0 = 0;
    return &lbl_804E46A0[idx];
}

int fn_801FE2A0(unsigned int arg0, int arg1) {
    char *base = lbl_80477190;
    Context *ctx;
    int t, r;
    int one = 1;
    lbl_805A09B8 = one;
    ctx = newContext(arg1, base, one);
    lbl_805A09BC++;
    if (lbl_805A09BC >= 4) lbl_805A09BC = 0;
    t = lbl_805A09BC;
    *(unsigned char *)(lbl_805A09D4 + (t << 5)) = 0xDD;
    ((int *)(lbl_805A09D4 + (lbl_805A09BC << 5)))[1] = (arg0 >> 16) & 3;
    r = fn_80212C08(lbl_8059EAF8, 0xDD, (void *)(lbl_805A09D4 + (lbl_805A09BC << 5)), 0x20, 0, 0, (void (*)(void))fn_801FC774, ctx);
    if (r != 0) {
        OSReport(base + 0xc4c, r);
        ctx->c = 0;
        return 0;
    }
    return 1;
}
