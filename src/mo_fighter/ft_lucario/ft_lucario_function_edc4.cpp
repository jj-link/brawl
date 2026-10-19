#pragma force_active on
extern "C" float rsqrtf__Ff(float);
extern "C" double __fabs(double);
extern const float lbl_118_rodata_5C;
extern const float lbl_118_rodata_30;

extern "C" float fn_118_EDC4(float* v) {
    float sum = v[0] * v[0] + v[1] * v[1];
    double d = __fabs((double)sum);
    float a = (float)d;
    if (a <= lbl_118_rodata_5C) {
        return lbl_118_rodata_30;
    }
    return sum * rsqrtf__Ff(sum);
}
