#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

extern void fn_801D7FCC(void *p);
extern void fn_801D81F4(void *p);
extern void fn_801E187C(void *p);
extern u16 *__peReg;
extern u8 lbl_805A08B8;
extern s8 lbl_805A08C0;
extern void (*lbl_805A08C4)(void);

void fn_801F0D2C(int unused, void *arg1) {
    u8 sp8[0x2d0];

    __peReg[5] = (u16)(__peReg[5] | 8);
    lbl_805A08C0 = 1;
    if (lbl_805A08C4 != 0) {
        fn_801D81F4(sp8);
        fn_801D7FCC(sp8);
        lbl_805A08C4();
        fn_801D81F4(sp8);
        fn_801D7FCC(arg1);
    }
    fn_801E187C(&lbl_805A08B8);
}
