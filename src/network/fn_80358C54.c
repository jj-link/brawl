#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern void fn_803360BC(int);
extern void fn_80355388(void);
extern void fn_803553C8(void);
extern char lbl_80415790[];
extern int lbl_8048E680[];

void fn_80358C54(void) {
    fn_80335638(4, lbl_80415790 + 0x22);
    if (lbl_8048E680[0] == 2) {
        fn_803360BC(lbl_8048E680[3]);
    }
    if (lbl_8048E680[0] == 3) {
        fn_80355388();
        fn_803553C8();
    }
    lbl_8048E680[0] = 0;
    lbl_8048E680[1] = 1;
}
