#pragma force_active on
extern int fn_801E5F48(void);
extern void fn_801E66F4(void *);
extern int fn_80215D5C(unsigned int);
extern void fn_80216BD4(void);
extern int lbl_8059ECE4;
extern int lbl_805A0C20;
extern int lbl_805A0C24;
extern int lbl_805A0C40;

int fn_80216B0C(int arg0) {
    int var_r31;
    int var_r3;

    if (lbl_805A0C24 != 0) {
        lbl_805A0C24 = 0;
        fn_801E66F4(&fn_80216BD4);
    }
    if (arg0 == 0) {
        var_r31 = 0;
        var_r3 = 0;
        if (lbl_805A0C40 == 0 && lbl_8059ECE4 == 0x20) {
            var_r3 = 1;
        }
        if (var_r3 != 0 && fn_801E5F48() == 0) {
            var_r31 = 1;
        }
        if (lbl_805A0C20 == 0 && var_r31 != 0) {
            lbl_805A0C20 = fn_80215D5C(0xF0000000);
            return 0;
        }
        return var_r31;
    }
    lbl_805A0C20 = 0;
    return 1;
}
