#pragma force_active on
extern "C" void fn_27_26399C(void*);
extern "C" const float lbl_67_rodata_10;

extern "C" void fn_67_3DAC(unsigned char* self, void* unused, const float* arg) {
    const float v = arg[1];
    fn_27_26399C(*reinterpret_cast<void**>(self + 0x14c));
    float* a = *reinterpret_cast<float**>(self + 0x15c);
    *a = *a - v;
    float* b = *reinterpret_cast<float**>(self + 0x15c);
    if (*b < lbl_67_rodata_10) {
        *b = lbl_67_rodata_10;
    }
}
