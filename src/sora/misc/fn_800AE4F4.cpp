#pragma force_active on
extern "C" void fn_800AE4F4(unsigned int *arg0) {
    unsigned int *var_r5 = arg0;
    unsigned int var_r6 = 0;
    while (var_r6 < arg0[3]) {
        var_r5[0x5E1] = 0;
        var_r5 += 1;
        var_r6 += 1;
    }
    arg0[3] = 0;
}
