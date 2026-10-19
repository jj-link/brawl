#pragma force_active on
extern "C" {
void fn_100_B818(float* dst, const float* src);
}
extern const float lbl_100_rodata_8;

extern "C" void fn_100_B7E0(float* obj) {
    float zero[2];
    zero[0] = lbl_100_rodata_8;
    zero[1] = lbl_100_rodata_8;
    fn_100_B818(obj + 2, zero);
}
