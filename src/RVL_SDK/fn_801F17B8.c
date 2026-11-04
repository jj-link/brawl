#pragma force_active on
extern const float lbl_805A37D8;
extern const double lbl_805A37E0;
extern unsigned int __cvt_fp2unsigned(float);
float fn_801F17B8(unsigned int arg0, unsigned int arg1) {
    float var_f28;
    float var_f29;
    unsigned int temp_r31;
    unsigned int var_r30;
    unsigned int var_r3;
    unsigned int var_r4;
    unsigned int var_r4_2;
    unsigned int var_r4_3;
    var_f29 = (float)arg1 / (float)arg0;
    var_r30 = arg1;
    var_r4 = (unsigned int)(lbl_805A37D8 / var_f29) & 0x1FF;
    temp_r31 = (arg0 - 1) << 8;
    var_r3 = (temp_r31 / var_r4) + 1;
    if ((var_r4 > 0x80U) && (var_r4 < 0x100U)) {
        while (!(var_r4 & 1U)) var_r4 >>= 1;
        if (arg0 % var_r4 == 0) var_r3++;
    }
    if (var_r3 > 0x400U) var_r3 = 0x400U;
    while (var_r3 > arg1) {
        var_r30--;
        var_f29 = (float)var_r30 / (float)arg0;
        var_r4_2 = (unsigned int)(lbl_805A37D8 / var_f29) & 0x1FF;
        var_r3 = temp_r31 / var_r4_2 + 1;
        if (var_r4_2 > 0x80U && var_r4_2 < 0x100U) {
            while (!(var_r4_2 & 1U)) var_r4_2 >>= 1;
            if (arg0 % var_r4_2 == 0) var_r3++;
        }
        if (var_r3 > 0x400U) var_r3 = 0x400U;
    }
    var_f28 = var_f29;
    while (var_r3 < arg1) {
        var_r30++;
        var_f28 = var_f29;
        var_f29 = (float)var_r30 / (float)arg0;
        var_r4_3 = (unsigned int)(lbl_805A37D8 / var_f29) & 0x1FF;
        var_r3 = temp_r31 / var_r4_3 + 1;
        if (var_r4_3 > 0x80U && var_r4_3 < 0x100U) {
            while (!(var_r4_3 & 1U)) var_r4_3 >>= 1;
            if (arg0 % var_r4_3 == 0) var_r3++;
        }
        if (var_r3 > 0x400U) var_r3 = 0x400U;
    }
    return var_f28;
}