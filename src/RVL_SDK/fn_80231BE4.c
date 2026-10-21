#pragma force_active on
extern void fn_802318FC(void);
extern void fn_8023235C(void);
extern void fn_802435AC(void);
extern signed char lbl_8059EDE8;
extern int lbl_8059EDEC;
extern int lbl_805A0D28;
extern int lbl_805A0D2C;

void fn_80231BE4(void) {
    lbl_8059EDE8 = 1;
    lbl_8059EDEC = 1;
    lbl_805A0D28 = 0;
    lbl_805A0D2C = 0;
    fn_802435AC();
    fn_802318FC();
    fn_8023235C();
}
