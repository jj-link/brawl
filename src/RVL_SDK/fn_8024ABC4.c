#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 lbl_8052CDC0[];
extern char lbl_80482878[];
extern void fn_80231A14(int, char *, int, int);
extern void fn_802319FC(int, char *, int);
extern void fn_802319E4(int, char *);
extern void fn_8022F0E0(void *);
extern u8 *fn_8024FC18(int, int);
extern void fn_8024AED0(void *, int, void *);

int fn_8024ABC4(int arg0, u8 *arg1) {
    char *s = lbl_80482878;
    u8 *p;
    if (lbl_8052CDC0[0] >= 3) {
        fn_80231A14(0x80002, s + 0x49c, arg0, *(u16 *)(arg1 + 2));
    }
    p = fn_8024FC18(0, arg0);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319FC(0x80001, s + 0x4c4, arg0);
        }
        fn_8022F0E0(arg1);
        return 0;
    }
    if (*(u16 *)(arg1 + 2) <= *(u16 *)(p + 0x3a)) {
        fn_8024AED0(p, 0x1d, arg1);
        return (((*(u8 **)(p + 0x10))[0x41]) != 0) + 1;
    }
    if (lbl_8052CDC0[0] >= 2) {
        fn_802319E4(0x80001, s + 0x4f0);
    }
    fn_8022F0E0(arg1);
    return 0;
}