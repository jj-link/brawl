#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern int fn_8035A078(int, int);
extern char lbl_80415790[];
extern int lbl_8048E680[];

void fn_80359A94(int arg0, int arg1, int arg2) {
    fn_80335638(4, lbl_80415790 + 0x497);
    if (arg2 != 0) {
        fn_80335638(8, lbl_80415790 + 0x4AE, arg2);
        fn_8035A078(2, arg2);
        lbl_8048E680[0] = 5;
        lbl_8048E680[1] = 3;
    } else {
        lbl_8048E680[0] = 8;
    }
}
