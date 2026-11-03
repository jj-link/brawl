#pragma force_active on
extern void fn_8035A1E4(int, void *, int, ...);
extern void fn_8033524C(int, int);
extern char lbl_80415D08[];

int fn_8035A100(int arg0, int arg1) {
    int var_r31;
    int var_r30;
    int temp_r5;

    var_r30 = 0x14;
    switch (arg1) {
    case 0:
        var_r30 = 0;
        var_r31 = 1;
        break;
    case 1:
        var_r31 = 0x17;
        break;
    case 2:
        var_r31 = 0x18;
        break;
    case 3:
        var_r31 = 0x19;
        break;
    case 4:
        var_r31 = 0x1a;
        break;
    case 5:
        var_r31 = 0x1b;
        break;
    case 6:
        var_r31 = 0x1c;
        break;
    default:
        var_r31 = 0x1c;
        break;
    }
    if (var_r31 != 1) {
        fn_8035A1E4(0x65, lbl_80415D08 + 0x11, var_r31);
        temp_r5 = arg0 * 0x64;
        fn_8033524C(var_r30, 0xFFFF63C0 - (var_r31 + temp_r5 + 0x32));
    }
    return var_r31;
}