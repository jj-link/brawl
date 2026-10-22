#pragma force_active on
extern void fn_802319FC(int, const char *, int);
extern void *fn_8024FC18(unsigned int, unsigned int);
extern void fn_8024AED0(void *, int, int);
extern const char lbl_80482C74[];
extern const char lbl_80482C98[];
extern unsigned char lbl_8052CDC0[];

int fn_8024AA7C(int arg0) {
    void *p;
    if (lbl_8052CDC0[0] >= 3) {
        fn_802319FC(0x80002, lbl_80482C74, arg0);
    }
    p = fn_8024FC18(0, arg0);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319FC(0x80001, lbl_80482C98, arg0);
        }
        return 0;
    }
    fn_8024AED0(p, 0x1a, 0);
    return 1;
}
