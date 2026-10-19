#pragma force_active on
extern "C" float fn_41_10894(float *p);
extern "C" float rsqrtf__Ff(float);
extern "C" double __fabs(double);
extern const float lbl_41_rodata_BF8;
extern const float lbl_41_rodata_BE0;

extern "C" float fn_41_10830(float *p) {
    float x = fn_41_10894(p);
    double d = __fabs(x);
    float ax = (float)d;
    if (ax <= lbl_41_rodata_BF8) {
        return lbl_41_rodata_BE0;
    }
    return x * rsqrtf__Ff(x);
}
