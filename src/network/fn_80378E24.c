#pragma force_active on
extern void *lbl_8059F9A8;

void fn_80378E24(void *arg0, int arg1) {
    char *var_r3;

    var_r3 = arg0;
    if (var_r3 == 0) {
        var_r3 = lbl_8059F9A8;
    }
    *(int *)(var_r3 + 0xA0) = arg1;
}
