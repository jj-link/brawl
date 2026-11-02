#pragma force_active on
extern void fn_8035A1E4(int, void *, int, ...);
extern void fn_8033524C(int, int);
extern char lbl_80415D08[];

int fn_80359F34(int arg0) {
    int var_r31;
    int var_r30;

    switch (arg0) {
    case 0:
        var_r30 = 0;
        var_r31 = 0;
        break;
    case 1:
        var_r30 = 8;
        var_r31 = 2;
        break;
    case 2:
        var_r30 = 8;
        var_r31 = 3;
        break;
    case 3:
        var_r30 = 9;
        var_r31 = 1;
        break;
    default:
        var_r31 = 0x11;
        break;
    }
    if (var_r31 != 0) {
        fn_8035A1E4(0x35, lbl_80415D08, var_r31);
        fn_8033524C(var_r30, 0xFFFF63C0 - (var_r31 + 0x64));
    }
    return var_r31;
}
