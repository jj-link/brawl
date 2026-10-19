#pragma force_active on
extern "C" {
extern const float lbl_93_rodata_64;
extern const float lbl_93_rodata_68;

float rsqrtf__Ff(float);

float fn_93_FE68(const float* vec) {
    float x = vec[0];
    float first = x * x;
    float y = vec[1];
    float sum = first + y * y;
    float magnitude = __fabsf(sum);
    float roundedMagnitude = (float)(double)magnitude;

    if (roundedMagnitude <= lbl_93_rodata_68) {
        return lbl_93_rodata_64;
    }

    return sum * rsqrtf__Ff(sum);
}
}
