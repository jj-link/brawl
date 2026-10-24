#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern s32 fn_8037B37C(void *, s32);
extern void fn_8037BBB8(void *);
extern void *fn_803F602C(void *, const void *, unsigned int);

typedef s32 (*CbFn)(void *, void *, char *, s32 *, char *, s32 *);

typedef struct Self {
    u8 pad0[0x9C];
    s32 buf9C;
    char *unkA0;
    s32 unkA4, unkA8, unkAC, unkB0;
    u8 padB4[0xC0 - 0xB4];
    s32 unkC0;
    char *unkC4;
    s32 unkC8, unkCC, unkD0;
    u8 padD4[0x190 - 0xD4];
    u8 buf190[0x1AC - 0x190];
    CbFn fn1AC;
} Self;

s32 fn_8037BE7C(Self *arg0) {
    s32 spC;
    s32 sp8;
    s32 r;
    s32 r30;
    char *c4;
    s32 d0;
    char *a0;
    s32 a8;
    char *input;
    char *output;

    spC = 0;
    sp8 = 0;
loop:
    d0 = arg0->unkD0;
    c4 = arg0->unkC4;
    spC = arg0->unkCC - d0;
    input = c4 + d0;
    a8 = arg0->unkA8;
    a0 = arg0->unkA0;
    sp8 = arg0->unkA4 - a8;
    output = a0 + a8;
    r = arg0->fn1AC(arg0, arg0->buf190, input, &spC, output, &sp8);
    r30 = r;
    if (r == 2) {
        if (fn_8037B37C(&arg0->buf9C, arg0->unkB0) == 0) {
            return 0;
        }
    } else if (r == 3) {
        return 0;
    }
    if (r30 != 2 || sp8 != 0) {
        if (spC > arg0->unkCC) {
            return 0;
        }
        arg0->unkD0 = arg0->unkD0 + spC;
        arg0->unkA8 = arg0->unkA8 + sp8;
        if (sp8 <= 0) {
            if (arg0->unkD0 > 0xFF) {
                r30 = arg0->unkCC - arg0->unkD0;
                if (r30 == 0) {
                    fn_8037BBB8(&arg0->unkC0);
                } else {
                    fn_803F602C(arg0->unkC4, arg0->unkC4 + arg0->unkD0, r30);
                    arg0->unkCC = r30;
                    arg0->unkD0 = 0;
                }
            }
            return 1;
        }
        goto loop;
    }
    goto loop;
}
