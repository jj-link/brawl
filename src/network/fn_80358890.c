#pragma force_active on
extern void fn_8035E390(void);
extern int fn_8038D394(void *);
extern int fn_80359F34(int);
extern int fn_80339438(int *);
extern void fn_80335638(int, const char *, ...);
extern void fn_8038D420(int, int, int, int);
extern void fn_8038D480(int, int, int *);
extern char lbl_80415790[];
extern int lbl_8048E680[];

int fn_80358890(int arg0, int arg1, int arg2, void *arg3, int arg4) {
    int sp8[8];
    fn_8035E390();
    if (fn_80359F34(fn_8038D394(&lbl_8048E680[2])) != 0) {
        return 2;
    }
    if (fn_80339438(sp8) == 0) {
        fn_80335638(8, lbl_80415790);
        return 1;
    }
    lbl_8048E680[18] = *(int *)((char *)arg3 + 0x1c);
    fn_8038D420(lbl_8048E680[2], arg0, arg1, arg2);
    fn_8038D480(lbl_8048E680[2], lbl_8048E680[18], sp8);
    lbl_8048E680[0] = 0;
    lbl_8048E680[1] = 1;
    lbl_8048E680[19] = arg4;
    return 0;
}