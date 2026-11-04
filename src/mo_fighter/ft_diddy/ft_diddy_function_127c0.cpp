#pragma force_active on
extern "C" float fn_115_E59C(float value);
extern const float lbl_115_rodata_C8;
extern const double lbl_115_rodata_D8;
extern "C" float fn_115_127C0(float a, float b, float c, float d) {
    float temp_f27 = b;
    float temp_f28 = d;
    float var_f30;
    float var_f29 = lbl_115_rodata_C8;
    if (a < lbl_115_rodata_C8) var_f29 = c;
    else if (a > lbl_115_rodata_C8) var_f29 = -c;
    if (b * var_f29 <= lbl_115_rodata_C8) {
        var_f30 = a + (b + var_f29);
        if (fn_115_E59C(b) < fn_115_E59C(var_f29)) {
            var_f30 += b + var_f29;
            if (var_f29 < lbl_115_rodata_C8) {
                if (var_f30 < lbl_115_rodata_C8) var_f30 = lbl_115_rodata_C8;
            } else if (var_f30 > lbl_115_rodata_C8) var_f30 = lbl_115_rodata_C8;
        }
    } else var_f30 = a + (b + var_f29);
    if (fn_115_E59C(var_f30) > temp_f28) {
        int s;
        if (var_f30 < lbl_115_rodata_C8) s = -1; else s = 1;
        var_f30 = d * (float)s;
    }
    return var_f30;
}