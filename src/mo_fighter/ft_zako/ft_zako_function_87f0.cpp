#pragma force_active on
extern "C" const float lbl_126_rodata_8;
extern "C" void fn_126_8828(float* dst, const float* src);

extern "C" void fn_126_87F0(float* object) {
    float zero[2];
    zero[0] = lbl_126_rodata_8;
    zero[1] = lbl_126_rodata_8;
    fn_126_8828(object + 2, zero);
}
