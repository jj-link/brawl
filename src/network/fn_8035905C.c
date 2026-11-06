#pragma force_active on
extern int fn_80355268(void);
extern void fn_8035912C(void);
extern void fn_803553C8(void);
extern void fn_80335638(int, const char *, ...);
extern int fn_8033514C(int *);
extern int lbl_8048E680[];
extern char lbl_80415790[];

void fn_8035905C(void) {
    switch (fn_80355268()) {
    case 8:
        fn_8035912C();
        fn_803553C8();
        break;
    case 0:
        lbl_8048E680[0] = 0;
        lbl_8048E680[1] = 1;
        fn_803553C8();
        break;
    case 1:
        fn_80335638(8, lbl_80415790 + 0x164);
        if (fn_8033514C(0) == 0) {
            lbl_8048E680[0] = 0;
            lbl_8048E680[1] = 11;
        } else {
            lbl_8048E680[0] = 5;
            lbl_8048E680[1] = 3;
        }
        fn_803553C8();
        break;
    }
}