#pragma force_active on
extern unsigned char lbl_8052CDC0[];
extern char lbl_80482C1C[];
extern char lbl_80482C48[];
extern void fn_80231A14(int, void *, int, int);
extern void fn_802319FC(int, void *, int);
extern void *fn_8024FC18(int, int);
extern void fn_8024AED0(void *, int, void *);

int fn_8024A9AC(int arg0, unsigned short *arg1) {
    void *p;
    if (lbl_8052CDC0[0] >= 3) {
        fn_80231A14(0x80002, lbl_80482C1C, arg0, *arg1);
    }
    p = fn_8024FC18(0, arg0);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319FC(0x80001, lbl_80482C48, arg0);
        }
        return 0;
    }
    if (*arg1 == 0) {
        fn_8024AED0(p, 0x18, arg1);
    } else {
        fn_8024AED0(p, 0x19, arg1);
    }
    return 1;
}