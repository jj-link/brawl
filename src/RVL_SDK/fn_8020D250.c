#pragma force_active on
extern int lbl_805A0BA8;
extern void fn_8020CFBC(int, int, int, int);
extern int fn_8020CAEC(void);

int fn_8020D250(int a) {
    if (lbl_805A0BA8 != 2) {
        return -0x80;
    }
    fn_8020CFBC(a, 0, 0, 0);
    return fn_8020CAEC();
}
