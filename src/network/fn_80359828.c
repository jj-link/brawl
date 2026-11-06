#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern int fn_8035A078(int, int);
extern int fn_8035A100(int, int);
extern const char *fn_8037EF4C(int);
extern int fn_8038D64C(const char *, int *);
extern int fn_8038D6F8(const char *, void *);
extern char lbl_80415790[];
extern int lbl_8048E680[];

void fn_80359828(int arg0, int arg1, int arg2) {
    int result;
    fn_80335638(4, lbl_80415790 + 0x3bc);
    if (arg2 != 0) {
        lbl_8048E680[0] = 5;
        lbl_8048E680[1] = 3;
        return;
    }
    if (fn_8038D64C(fn_8037EF4C(lbl_8048E680[3]), &result) == 0) {
        fn_80335638(8, lbl_80415790 + 0x3d2);
        fn_8035A078(6, 0x15);
        lbl_8048E680[0] = 5;
        lbl_8048E680[1] = 3;
        return;
    }
    if (result != 0) {
        fn_80335638(8, lbl_80415790 + 0x400, result);
        fn_8035A100(6, result);
        lbl_8048E680[0] = 5;
        lbl_8048E680[1] = 3;
        return;
    }
    if (fn_8038D6F8(fn_8037EF4C(lbl_8048E680[3]), &lbl_8048E680[10]) == 0) {
        fn_80335638(8, lbl_80415790 + 0x431);
        fn_8035A078(6, 0x15);
        lbl_8048E680[0] = 5;
        lbl_8048E680[1] = 3;
        return;
    }
    lbl_8048E680[0] = 7;
}