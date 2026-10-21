#pragma force_active on
typedef signed short s16;

extern unsigned int fn_803EB068(int a, unsigned int *b);
extern void fn_803D65A4(unsigned int value, short *hi, short *lo);

s16 fn_803EB380(int param) {
    unsigned int spC;
    short spA;
    short sp8;
    unsigned int v;

    v = fn_803EB068(param, &spC);
    fn_803D65A4(v, &spA, &sp8);
    return sp8;
}
