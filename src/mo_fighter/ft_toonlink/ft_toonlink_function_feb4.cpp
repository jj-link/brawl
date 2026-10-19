#pragma force_active on
extern "C" float rsqrtf__Ff(float);
extern "C" const float lbl_121_rodata_68;
extern "C" const float lbl_121_rodata_64;

extern "C" float fn_121_FEB4(const float* v) {
    float sum = v[0] * v[0] + v[1] * v[1];
    double magnitude = __fabs(sum);

    if ((float)magnitude <= lbl_121_rodata_68) {
        return lbl_121_rodata_64;
    }

    return sum * rsqrtf__Ff(sum);
}
