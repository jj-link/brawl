#pragma force_active on
extern unsigned char fn_8020FCF0(void);
extern int lbl_805A0840;

int fn_801E9F0C(int arg0) {
    int temp_r31;
    int var_r30;

    var_r30 = arg0;
    temp_r31 = lbl_805A0840;
    if ((arg0 == 1) && (fn_8020FCF0() == 0)) {
        var_r30 = 0;
    }
    lbl_805A0840 = var_r30;
    return temp_r31;
}
