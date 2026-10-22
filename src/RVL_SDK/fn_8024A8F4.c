#pragma force_active on
extern unsigned char lbl_8052CDC0[];
extern char lbl_80482BD0[];
extern char lbl_80482BF0[];
extern void fn_802319FC(int, void *, void *);
extern void *fn_8024FC18(int, void *);
extern void fn_8024AED0(void *, int, void *);

int fn_8024A8F4(void *arg0, void *arg1) {
    void *p;

    if (lbl_8052CDC0[0] >= 3) {
        fn_802319FC(0x80002, lbl_80482BD0, arg0);
    }
    p = fn_8024FC18(0, arg0);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319FC(0x80001, lbl_80482BF0, arg0);
        }
        return 0;
    }
    ((unsigned char *)arg1)[0x24] = 0;
    fn_8024AED0(p, 0x17, arg1);
    return 1;
}
