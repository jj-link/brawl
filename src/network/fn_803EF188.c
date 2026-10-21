#pragma force_active on
extern void fn_801C92E4(int);
extern void fn_803EF640(void);

void fn_803EF188(int *arg0) {
    if (*arg0 != 0) {
        fn_803EF640();
        fn_801C92E4(*arg0);
    }
}
