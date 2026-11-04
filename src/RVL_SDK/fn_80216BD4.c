#pragma force_active on
extern void fn_801D7FCC(void *);
extern void fn_801D81F4(void *);
extern void (*lbl_805A0C24)(void);

void fn_80216BD4(int unused, void *arg1) {
    unsigned char sp8[0x2d0];
    if (lbl_805A0C24 != 0) {
        fn_801D81F4(sp8);
        fn_801D7FCC(sp8);
        lbl_805A0C24();
        fn_801D81F4(sp8);
        fn_801D7FCC(arg1);
    }
}