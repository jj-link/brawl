#pragma force_active on
extern "C" {
extern const float lbl_100_rodata_8;
}

extern "C" void fn_100_B8DC(float* v) {
    float zero = lbl_100_rodata_8;
    v[0] = zero;
    v[1] = zero;
    v[2] = zero;
}
