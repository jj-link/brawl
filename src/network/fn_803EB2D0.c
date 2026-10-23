#pragma force_active on
typedef signed short s16;

extern unsigned int fn_803EAEAC(unsigned int value, unsigned int *p);
extern void fn_803D65A4(unsigned int value, short *hi, short *lo);

s16 fn_803EB2D0(unsigned int param) {
    unsigned int spC;
    short spA;
    short sp8;
    unsigned int v;

    v = fn_803EAEAC(param, &spC);
    fn_803D65A4(v, &spA, &sp8);
    return spA;
}
