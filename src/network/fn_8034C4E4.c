#pragma force_active on
typedef unsigned char u8;
extern u8 lbl_805338B0[];
extern char lbl_8048CBB8[];
extern int fn_8037925C(u8 *, int);
extern void fn_80335638(int, const char *, ...);
void fn_8034C4E4(int arg0, u8 *arg1) {
    u8 *p;
    int i;
    switch (arg0) {
    case 0:
        fn_8037925C(arg1, 8);
        fn_8037925C(arg1, 10);
        fn_8037925C(arg1, 0x32);
        fn_8037925C(arg1, 0x33);
        fn_8037925C(arg1, 0x34);
        fn_8037925C(arg1, 0x35);
        fn_8037925C(arg1, 0x36);
        fn_8037925C(arg1, 0x37);
        fn_8037925C(arg1, 0x38);
        fn_8037925C(arg1, 0x39);
        fn_8037925C(arg1, 0x3a);
        p = lbl_805338B0;
        for (i = 0; i < 0x9a; i++, p += 12) {
            if (*p)
                fn_8037925C(arg1, *p);
        }
        break;
    case 1:
    case 2:
        break;
    }
    fn_80335638(0x200, lbl_8048CBB8, arg0);
}