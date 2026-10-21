#pragma force_active on
extern void fn_801FF36C(void);
extern void fn_801FF878(void);
extern void fn_802009C4(void);
extern void fn_80201078(void);
extern void fn_80201518(void);
extern void fn_80202204(void);
extern int lbl_805A0A20;

void fn_801FF1AC(void) {
    if (lbl_805A0A20 != 0) {
        fn_80201078();
        fn_801FF36C();
        fn_80202204();
        fn_80201518();
        fn_801FF878();
        fn_802009C4();
        lbl_805A0A20 = 0;
    }
}
