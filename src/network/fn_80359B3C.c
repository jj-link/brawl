#pragma force_active on
#pragma fp_contract on
extern char lbl_80415790[];
extern int lbl_8048E680[];
extern void fn_80335638(int, const char *, ...);
extern int fn_80358F08(const char *, int *, int);
extern void fn_803F8ACC(void *, unsigned int, unsigned int, int (*)(int *, int *));
extern double fn_80400B44(double, double);
extern int fn_80359B2C(int *, int *);
extern void *memcpy(void *, const void *, unsigned long);

#define BSWAP32(x) \
    ((((unsigned int)(x) >> 24) | (((unsigned int)(x) >> 8) & 0xFF00)) | \
     (((unsigned int)(x) << 24) | (((unsigned int)(x) << 8) & 0xFF0000)))

void fn_80359B3C(void)
{
    int sp8[4];
    int buf[5];
    int mul;
    int *p;
    int last;
    int idx;
    int acc;
    int count;
    int tmp;
    int v;
    int i;
    double f;

    last = -1;
    idx = 0;
    acc = 0;

    fn_80335638(4, lbl_80415790 + 0x4E6);

    buf[1] = BSWAP32(lbl_8048E680[10]);
    buf[2] = BSWAP32(lbl_8048E680[9]);

    switch (lbl_8048E680[7]) {
    case 0:
        buf[0] = 0x01000000;
        tmp = *(int *)lbl_8048E680[11];
        buf[3] = BSWAP32(tmp);
        memcpy(sp8, (char *)lbl_8048E680[11] + 4, ((int *)lbl_8048E680[11])[5] * 4);
        fn_803F8ACC(sp8, ((int *)lbl_8048E680[11])[5] & 0xFFFF, 4, fn_80359B2C);
        count = ((int *)lbl_8048E680[11])[5];
        mul = lbl_8048E680[19];
        p = sp8;
        for (i = 0; i < count; p++, i++) {
            v = *p;
            if (last != v) {
                acc = (int)((double)v * fn_80400B44((double)mul, (double)idx) + (double)acc);
                last = v;
                idx += 1;
            }
        }
        buf[4] = BSWAP32(acc);
        break;
    case 1:
    case 2:
    case 3:
        buf[0] = 0x02000000;
        buf[3] = 0;
        buf[4] = 0;
        break;
    case 4:
        buf[0] = 0x03000000;
        buf[3] = 0;
        buf[4] = 0;
        break;
    default:
        break;
    }

    if (fn_80358F08(lbl_80415790 + 0x509, buf, 0x14) == 0) {
        lbl_8048E680[0] = 5;
        lbl_8048E680[1] = 3;
    } else {
        lbl_8048E680[0] = 3;
    }
}
