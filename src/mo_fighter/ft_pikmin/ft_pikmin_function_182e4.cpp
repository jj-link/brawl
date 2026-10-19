#pragma force_active on
extern "C" {
extern const float lbl_113_rodata_6C;
extern const float lbl_113_rodata_64;
float rsqrtf__Ff(float);

float fn_113_182E4(float* v) {
    float sum = v[0] * v[0] + v[1] * v[1];
    double d = __fabs((double)sum);
    float a = d;
    if (a <= lbl_113_rodata_6C) {
        return lbl_113_rodata_64;
    }
    return sum * rsqrtf__Ff(sum);
}
}
