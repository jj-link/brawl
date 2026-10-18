#pragma force_active on
extern "C" {
extern const float lbl_100_rodata_78;
}

extern "C" void fn_100_132A0(float* p) {
    float v = lbl_100_rodata_78;
    p[3] = v;
    p[2] = v;
}
