#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern void memcpy(void *, void *, int);
extern char lbl_80415790[];
extern int lbl_8048E680[];

void fn_80359E78(void *a, int b, int c) {
    fn_80335638(4, lbl_80415790 + 0x535);
    if (c != 0) {
        fn_80335638(8, lbl_80415790 + 0x54A, c);
        lbl_8048E680[0] = 5;
        lbl_8048E680[1] = 3;
        return;
    }
    memcpy((void *)lbl_8048E680[12], a, b);
    lbl_8048E680[0] = 0;
    lbl_8048E680[1] = 0;
}
