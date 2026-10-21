#pragma force_active on
extern int lbl_805A0A9C;
extern int lbl_805A0AA0;
extern int lbl_805A0AA4;

int fn_8020111C(void) {
    int temp_r3;
    int var_r3;

    var_r3 = lbl_805A0AA0 - 0x24;
    if (var_r3 < 0) {
        var_r3 += lbl_805A0AA4;
    }
    temp_r3 = var_r3 - lbl_805A0A9C;
    if (temp_r3 < 0) {
        return temp_r3 + lbl_805A0AA4;
    }
    return temp_r3;
}
