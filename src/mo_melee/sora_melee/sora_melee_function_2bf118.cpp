#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_5FB4;
void fn_27_2BF118(float *p);
}

extern "C" void fn_27_2BF118(float *p) {
    const float value = lbl_27_rodata_5FB4;
    p[0] = value;
    p[1] = value;
    p[2] = value;
}
