#pragma force_active on
extern void fn_802319FC(int, void *, int);
extern void fn_8024AED0(void *a, int b, int c);
extern int fn_8024FC18(int, int);
extern char lbl_80482CC4[];
extern char lbl_80482CE8[];
extern unsigned char lbl_8052CDC0[];

int fn_8024AB20(int arg0) {
    int r;
    if (lbl_8052CDC0[0] >= 3) {
        fn_802319FC(0x80002, lbl_80482CC4, arg0);
    }
    r = fn_8024FC18(0, arg0);
    if (r == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319FC(0x80001, lbl_80482CE8, arg0);
        }
        return 0;
    }
    fn_8024AED0((void *)r, 0x1B, 0);
    return 1;
}
