#pragma force_active on
extern "C" {
float fn_801622C4(float);
float fn_8016232C(float);
extern const float lbl_74_rodata_17C;
}

extern "C" void fn_74_C390(void* unused, float* out, float angle, float a, float b) {
    float s = fn_801622C4(lbl_74_rodata_17C * angle);
    float c = fn_8016232C(lbl_74_rodata_17C * angle);
    out[0] = a * c - b * s;
    out[1] = a * s + b * c;
}
