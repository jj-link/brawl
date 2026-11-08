#pragma force_active on
extern int lbl_8048E680[];
extern void fn_803596B8(void);
extern int fn_80335A80(void);
extern void fn_8035905C(void);
extern void fn_8035E69C(unsigned int);
extern int fn_803359CC(void);
extern void fn_80359978(void);
extern void fn_80359B3C(void);
extern void fn_80359D78(void);
extern int fn_8035E848(void);

int fn_80358CD4(void) {
    switch (lbl_8048E680[0]) {
    case 6:
        fn_803596B8();
        break;
    case 2:
        fn_80335A80();
        break;
    case 3:
        fn_8035905C();
        break;
    case 4:
        fn_8035E69C(0);
        break;
    case 7:
        fn_803359CC();
        fn_80359978();
        break;
    case 8:
        fn_80359B3C();
        break;
    case 9:
        fn_80359D78();
        break;
    case 10:
        fn_8035E69C(0);
        if (fn_8035E848() != 0) {
            lbl_8048E680[0] = 1;
            lbl_8048E680[1] = 4;
        }
        break;
    }
    return lbl_8048E680[1];
}