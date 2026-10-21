#pragma force_active on
int fn_803D4808(int arg0) {
    int var_r4;

    var_r4 = 0;
    if (arg0 & 0x20) {
        var_r4 = 0x800;
    }
    if (arg0 & 0x40) {
        var_r4 += 0x2000;
    }
    if (arg0 & 0x80) {
        var_r4 += 0x8000;
    }
    if (arg0 & 0x100) {
        var_r4 += 0x20000;
    }
    return var_r4;
}
