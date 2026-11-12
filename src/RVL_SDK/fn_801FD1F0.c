#pragma global_optimizer off
#include <revolution/OS/OSError.h>
#pragma force_active on

extern char lbl_80477190[];
extern unsigned char lbl_805A09B8;
extern int lbl_805A09BC, lbl_805A09C0;
extern unsigned int lbl_805A09D4;
extern int lbl_8059EAF8;
extern unsigned int fn_801FC774(unsigned int, void *);
extern int fn_80212FAC(int, int, int, int, void *, void (*)(void), void *);

typedef struct {
    int a, b;
    unsigned char c;
    unsigned int magic, id;
    char pad[12];
} Context;

extern Context lbl_804E46A0[4];
extern unsigned int lbl_804E4760[6];

static inline Context *newContext(int arg, char *base, int one) {
    int idx = lbl_805A09C0;

    if ((unsigned int)(lbl_804E46A0[idx].c != 0) == 1) {
        OSReport(base + 0x240, idx);
        OSReport(base + 0x278);
        for (;;) {
        }
    }
    if (lbl_804E46A0[idx].magic != 0xFEEBDAED) {
        OSReport(base + 0x2A8);
        for (;;) {
        }
    }
    lbl_804E46A0[idx].a = arg;
    lbl_804E46A0[idx].b = one;
    lbl_804E46A0[idx].c = (unsigned char)one;
    lbl_805A09C0 = idx + 1;
    if (lbl_805A09C0 >= 4) {
        lbl_805A09C0 = 0;
    }
    return &lbl_804E46A0[idx];
}

int fn_801FD1F0(void *buf, unsigned int *numTmdBytes,
                unsigned int *certsSize, void (*callback)(void)) {
    char *base = lbl_80477190;
    Context *ctx;
    int t, r;
    int one;

    if (numTmdBytes == 0 || certsSize == 0) {
        OSReport(base + 0x560, base + 0x544);
        return 0;
    }
    if ((unsigned int)numTmdBytes & 0x1F) {
        OSReport(base + 0x584, base + 0x544);
        return 0;
    }
    if ((unsigned int)certsSize & 0x1F) {
        OSReport(base + 0x5AC, base + 0x544);
        return 0;
    }

    one = 1;
    lbl_805A09B8 = one;
    ctx = newContext((int)callback, base, one);

    lbl_805A09BC++;
    if (lbl_805A09BC >= 4) {
        lbl_805A09BC = 0;
    }
    t = lbl_805A09BC;
    *(unsigned char *)(lbl_805A09D4 + (t << 5)) = 0x92;
    {
        int off = lbl_805A09BC << 5;
        unsigned int ptr = lbl_805A09D4;
        *(int *)(ptr + off + 4) = (int)buf;
    }

    lbl_804E4760[0] = lbl_805A09D4 + (lbl_805A09BC << 5);
    lbl_804E4760[2] = (unsigned int)numTmdBytes;
    lbl_804E4760[4] = (unsigned int)certsSize;
    lbl_804E4760[1] = 0x20;
    lbl_804E4760[3] = 4;
    lbl_804E4760[5] = 4;

    r = fn_80212FAC(lbl_8059EAF8, 0x92, 1, 2, lbl_804E4760,
                    (void (*)(void))fn_801FC774, ctx);
    if (r != 0) {
        OSReport(base + 0x5D4, base + 0x544, r);
        ctx->c = 0;
        return 0;
    }
    return 1;
}
