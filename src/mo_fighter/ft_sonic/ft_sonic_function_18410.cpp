#pragma force_active on
extern "C" {
extern const float lbl_123_rodata_A4;
extern const float lbl_123_rodata_9C;
float rsqrtf__Ff(float);

float fn_123_18410(float* v) {
    float sum = v[0] * v[0] + v[1] * v[1];
    double d = __fabs((double)sum);
    float a = d;
    if (a <= lbl_123_rodata_A4) {
        return lbl_123_rodata_9C;
    }
    return sum * rsqrtf__Ff(sum);
}
}
