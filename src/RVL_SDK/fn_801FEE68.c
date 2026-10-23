#pragma force_active on
typedef void (*FnPtr)(void);
typedef unsigned short u16;
typedef unsigned char u8;

extern void fn_801D81F4();
extern void fn_801D7FCC(void *p);
extern void fn_801FEF10(FnPtr callback);
extern int lbl_805A09E4;
extern int lbl_805A0A14;
extern FnPtr lbl_805A0A18;

void fn_801FEE68(void *unused, void *arg1)
{
    u8 sp8[0x2c8];
    int r5;

    r5 = *(u16 *)0xCC00500A;
    *(u16 *)0xCC00500A = (r5 & -0xA1) | 8;
    fn_801D81F4(sp8, arg1);
    fn_801D7FCC(sp8);

    if (lbl_805A0A18 != 0 && lbl_805A09E4 == 0) {
        lbl_805A09E4 = 1;
        if (lbl_805A0A14 != 0) {
            fn_801FEF10(lbl_805A0A18);
        } else {
            lbl_805A0A18();
        }
        lbl_805A09E4 = 0;
    }

    fn_801D81F4(sp8);
    fn_801D7FCC(arg1);
}
