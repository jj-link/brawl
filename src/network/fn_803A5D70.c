#pragma force_active on
extern int fn_803A28EC(void);
extern int fn_803A2890(char *, int, int, void *, int, void *, int, int *);
extern char lbl_80492474[];
extern int lbl_80537640[8];
extern char lbl_80537660[];
extern int lbl_8059FE08;
extern int lbl_805A11D0;
extern int lbl_805A11D4;
extern int lbl_805A11D8;

int fn_803A5D70(int arg0, int arg1) {
    if (arg0 != 0) return 1;
    if (lbl_805A11D4 != 0) {
        if (fn_803A28EC() != 0) return 0;
        if (lbl_805A11D8 >= 0) return 1;
        if (lbl_805A11D0 > 0) {
            lbl_805A11D4 = 0;
            lbl_805A11D0 -= 1;
        } else {
            return 1;
        }
    } else {
        lbl_80537640[0] = arg1;
        if (fn_803A2890(lbl_80492474, lbl_8059FE08, 0x28, lbl_80537640, 0x20, lbl_80537660, 0x20, &lbl_805A11D8) >= 0) {
            lbl_805A11D4 = 1;
        }
    }
    return 0;
}