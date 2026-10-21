#pragma force_active on
extern int lbl_8059F598;

void fn_8035DA18(int arg0) {
    int var_r0;

    var_r0 = 1;
    if (arg0 != 0) {
        var_r0 = arg0 & 0x7FFFFFFF;
    }
    lbl_8059F598 = var_r0;
}
