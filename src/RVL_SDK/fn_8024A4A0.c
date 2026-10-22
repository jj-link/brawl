#pragma force_active on
extern void fn_802319FC(int, const char *, int);
extern int fn_8024FCD0(int);
extern void fn_8024FCC0(void);
extern const char lbl_80482920[];
extern const char lbl_80482954[];
extern unsigned char lbl_8052CDC0[];

void fn_8024A4A0(int arg0) {
    if (lbl_8052CDC0[0] >= 3) {
        fn_802319FC(0x80002, lbl_80482920, arg0);
    }
    if (fn_8024FCD0(arg0) != 0) {
        fn_8024FCC0();
        return;
    }
    if (lbl_8052CDC0[0] >= 2) {
        fn_802319FC(0x80001, lbl_80482954, arg0);
    }
}
