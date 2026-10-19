#pragma force_active on
extern "C" const float lbl_115_rodata_C;
extern "C" void fn_115_C8BC(float* dst, const float* src);

extern "C" void fn_115_C884(float* object) {
    float zero = lbl_115_rodata_C;
    float values[2] = {zero, zero};
    fn_115_C8BC(object + 2, values);
}
