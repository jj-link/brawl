#pragma global_optimizer off
#include <revolution/OS/OSError.h>
#pragma force_active on
extern char lbl_80477190[];
extern unsigned char lbl_805A09B8;
extern int lbl_805A09BC, lbl_805A09C0;
extern unsigned int lbl_805A09D4;
extern int lbl_8059EAF8;
extern int lbl_804E4740[];
extern int fn_801FC82C(unsigned int, void *);
extern int fn_80212C08(int, int, void *, int, int, int, void (*)(void), void *);
typedef struct { int a, b; unsigned char c; unsigned int magic, id; char pad[12]; } Context;
extern Context lbl_804E46A0[4];

int fn_801FE768(int arg0) {
    char *base = lbl_80477190;
    Context *ctx;
    int r;

    lbl_805A09BC++;
    if (lbl_805A09BC >= 4) lbl_805A09BC = 0;
    *(unsigned char *)(lbl_805A09D4 + (lbl_805A09BC << 5)) = 0x7A;

    lbl_805A09B8 = 1;
    {
        int idx = lbl_805A09C0;
        if ((unsigned int)(lbl_804E46A0[idx].c != 0) == 1) {
            OSReport(base + 0x240, idx);
            OSReport(base + 0x278);
            for (;;) {}
        }
        if ((unsigned int)(lbl_804E46A0[idx].magic + 0x01150000) != 0xDAED) {
            OSReport(base + 0x2a8);
            for (;;) {}
        }
        lbl_804E46A0[idx].a = arg0;
        lbl_804E46A0[idx].b = 1;
        lbl_804E46A0[idx].c = 1;
        lbl_805A09C0 = idx + 1;
        if (lbl_805A09C0 >= 4) lbl_805A09C0 = 0;
        ctx = &lbl_804E46A0[idx];
    }

    r = fn_80212C08(lbl_8059EAF8, 0x7A, (void *)(lbl_805A09D4 + (lbl_805A09BC << 5)), 0x20, (int)lbl_804E4740, 0x20, (void (*)(void))fn_801FC82C, ctx);
    if (r != 0) {
        OSReport(base + 0xdb0, r);
        ctx->c = 0;
        return 0;
    }
    return 1;
}
