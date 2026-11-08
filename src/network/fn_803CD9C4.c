#pragma force_active on
extern int fn_803CD32C(void);
extern void *fn_803CD2E0(void);
extern int fn_803CFF50(int a, void *b, void *c);
extern void fn_803CFBE4(int a, void *b);
extern void fn_803CCEBC(void);
extern void fn_803CD920(void);

void fn_803CD9C4(void) {
    int r;
    char *p;

    if (fn_803CD32C() == 0) {
        p = (char *)fn_803CD2E0();
        *(int *)(p + 0x90) = 0;
        r = fn_803CFF50(1, p + 0x90, (void *)fn_803CD920);
        if ((r != 6) && ((r >= 6) || (r != 0))) {
            fn_803CFBE4(1, 0);
        }
    } else {
        fn_803CCEBC();
    }
}
