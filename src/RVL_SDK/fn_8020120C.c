#pragma force_active on
extern int lbl_805A0A9C;
extern int lbl_805A0AA0;
extern int lbl_805A0AA4;

void fn_8020120C(int arg0) {
    int var_r3;
    int var_r4;

    var_r3 = arg0;
    var_r4 = lbl_805A0AA0;
    var_r4 -= 0x24;
    if (var_r4 < 0) {
        var_r4 += lbl_805A0AA4;
    }
    var_r4 = var_r4 - lbl_805A0A9C;
    if (var_r4 < 0) {
        var_r4 += lbl_805A0AA4;
    }
    if (var_r3 > var_r4) {
        var_r3 = var_r4;
    }
    lbl_805A0A9C = lbl_805A0A9C + var_r3;
    if (lbl_805A0A9C >= lbl_805A0AA4) {
        lbl_805A0A9C = lbl_805A0A9C - lbl_805A0AA4;
    }
}
