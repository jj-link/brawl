#pragma force_active on
extern char *lbl_805A0A8C;
extern int lbl_805A0A84;
extern int lbl_805A0A88;
extern int lbl_805A0A80;
extern unsigned short lbl_805A0A78;
extern unsigned short lbl_805A0A7A;
extern unsigned short lbl_805A0A7C;
extern unsigned short lbl_805A0A7E;
extern char lbl_80478180[];

extern unsigned int fn_80201264(void);
extern unsigned int fn_80201EF0(void);
extern void fn_801FF88C(unsigned int *out);
extern void fn_801FF8C0(unsigned int *out, char *a, char *b);
extern void fn_801FF8DC(unsigned int *out, char *a, char *b);
extern void fn_801FF8FC(unsigned int *out, char *a, char *b);
extern void fn_801FF91C(unsigned int *out, char *a, char *b);
extern void fn_801FF93C(unsigned int *out, char *a, char *b);
extern void fn_801FF95C(unsigned int *out);
extern void fn_801FF990(unsigned int *out, char *a, char *b);
extern void fn_801FF9AC(unsigned int *out, char *a, char *b);
extern void fn_801FF9CC(unsigned int *out, char *a, char *b);
extern void fn_801FF9EC(unsigned int *out, char *a, char *b);
extern void fn_801FFA0C(unsigned int *out, char *a, char *b);
extern void fn_801FFA2C(unsigned int *out);
extern void fn_801FFA60(unsigned int *out, char *a, char *b);
extern void DCFlushRange(void *addr, unsigned int size);

#define PUT(v) do { *(unsigned short *)lbl_805A0A8C = (unsigned short)(v); lbl_805A0A8C += 2; } while (0)
#define STORE(v) do { *(unsigned short *)lbl_805A0A8C = (unsigned short)(v); } while (0)
#define CALLF(f) do { char *t_ = lbl_805A0A8C; lbl_805A0A8C = t_ + 2; f(&sp8, t_, t_ + 2); } while (0)
#define CALLF1(f) do { f(&sp8); } while (0)

void fn_801FFFC8(unsigned int arg0, unsigned int arg1, unsigned int *arg2) {
    unsigned int sp8;
    char *start = lbl_805A0A8C;

    lbl_805A0A84 = 0x1E83;
    sp8 = fn_80201264();
    PUT(0);
    PUT(sp8 >> 16);
    PUT(sp8);
    lbl_805A0A84 += 0x101E;
    switch (lbl_805A0A88) {
    case 0:
        PUT(1);
        PUT(arg0 >> 16);
        PUT(arg0);
        lbl_805A0A84 += 0x2DD;
        break;
    case 1:
        PUT(2);
        PUT(arg0 >> 16);
        PUT(arg0);
        lbl_805A0A84 += 0x33D;
        break;
    case 2:
        PUT(3);
        PUT(arg0 >> 16);
        PUT(arg0);
        lbl_805A0A84 += 0x39D;
        break;
    }
    sp8 = fn_80201EF0();
    PUT(4);
    PUT(sp8 >> 16);
    PUT(sp8);
    if ((unsigned int)lbl_805A0A88 == 2) {
        CALLF1(fn_801FF88C);
        if (sp8 != 0) {
            PUT(8);
            PUT(lbl_805A0A7C);
            PUT(sp8 >> 16);
            STORE(sp8);
            CALLF(fn_801FF8DC);
            PUT(sp8 >> 16);
            STORE(sp8);
            CALLF(fn_801FF8C0);
            PUT(sp8 >> 16);
            STORE(sp8);
            CALLF(fn_801FF8FC);
            PUT(sp8 >> 16);
            STORE(sp8);
            CALLF(fn_801FF91C);
            PUT(sp8 >> 16);
            STORE(sp8);
            CALLF(fn_801FF93C);
            PUT(sp8 >> 16);
            STORE(sp8);
            lbl_805A0A8C += 2;
            lbl_805A0A84 += 0xBDC;
        }
        CALLF1(fn_801FF95C);
        if (sp8 != 0) {
            PUT(9);
            PUT(lbl_805A0A7A);
            PUT(sp8 >> 16);
            STORE(sp8);
            CALLF(fn_801FF9AC);
            PUT(sp8 >> 16);
            STORE(sp8);
            CALLF(fn_801FF990);
            PUT(sp8 >> 16);
            STORE(sp8);
            CALLF(fn_801FF9CC);
            PUT(sp8 >> 16);
            STORE(sp8);
            CALLF(fn_801FF9EC);
            PUT(sp8 >> 16);
            STORE(sp8);
            CALLF(fn_801FFA0C);
            PUT(sp8 >> 16);
            STORE(sp8);
            lbl_805A0A8C += 2;
            lbl_805A0A84 += 0xBDC;
        }
    } else {
        CALLF1(fn_801FF88C);
        if (sp8 != 0) {
            PUT(5);
            PUT(lbl_805A0A7C);
            PUT(sp8 >> 16);
            STORE(sp8);
            CALLF(fn_801FF8C0);
            PUT(sp8 >> 16);
            STORE(sp8);
            lbl_805A0A8C += 2;
            lbl_805A0A84 += 0x8BB;
        }
        CALLF1(fn_801FF95C);
        if (sp8 != 0) {
            PUT(6);
            PUT(lbl_805A0A7A);
            PUT(sp8 >> 16);
            STORE(sp8);
            CALLF(fn_801FF990);
            PUT(sp8 >> 16);
            STORE(sp8);
            lbl_805A0A8C += 2;
            lbl_805A0A84 += 0x8BB;
        }
        CALLF1(fn_801FFA2C);
        if (sp8 != 0) {
            PUT(7);
            PUT(lbl_805A0A78);
            PUT(sp8 >> 16);
            STORE(sp8);
            CALLF(fn_801FFA60);
            PUT(sp8 >> 16);
            STORE(sp8);
            lbl_805A0A8C += 2;
            lbl_805A0A84 += 0x8BB;
        }
    }
    if (lbl_805A0A80 != 0) {
        PUT(0xA);
        PUT(0x8000);
        PUT(0xA);
        PUT((unsigned int)lbl_80478180 >> 16);
        PUT((unsigned int)lbl_80478180);
        lbl_805A0A84 += 0x73A;
    }
    PUT(0xD);
    PUT(arg2[0] >> 16);
    PUT(arg2[0]);
    PUT(arg2[1] >> 16);
    PUT(arg2[1]);
    PUT(arg2[2] >> 16);
    PUT(arg2[2]);
    PUT(arg2[3] >> 16);
    PUT(arg2[3]);
    lbl_805A0A84 += 0x199;
    if ((unsigned int)lbl_805A0A88 == 2) {
        PUT(0xC);
        PUT(lbl_805A0A7E);
        PUT(arg0 >> 16);
        PUT(arg0);
        PUT(arg1 >> 16);
        STORE(arg1);
        lbl_805A0A8C += 2;
        lbl_805A0A84 += 0x4AB;
    } else {
        PUT(0xB);
        PUT(lbl_805A0A7E);
        PUT(arg0 >> 16);
        PUT(arg0);
        PUT(arg1 >> 16);
        STORE(arg1);
        lbl_805A0A8C += 2;
        lbl_805A0A84 += 0x494;
    }
    PUT(0xE);
    lbl_805A0A84 += 0x1E;
    DCFlushRange(start, 0x80);
}
