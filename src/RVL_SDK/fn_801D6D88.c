#pragma force_active on
extern int fn_801FB6A0(void *);
extern void OSCancelAlarm(void *);
extern void *lbl_805A0678;

int fn_801D6D88(int arg0) {
    void *var_r31;
    void *var_r30;

    if (arg0 != 0) {
        var_r31 = lbl_805A0678;
        if (var_r31 != 0) {
            var_r30 = ((void **)var_r31)[5];
        } else {
            var_r30 = 0;
        }
        while (var_r31 != 0) {
            if (fn_801FB6A0(var_r31) == 0) {
                OSCancelAlarm(var_r31);
            }
            var_r31 = var_r30;
            if (var_r30 != 0) {
                var_r30 = ((void **)var_r30)[5];
            } else {
                var_r30 = 0;
            }
        }
    }
    return 1;
}
