#pragma force_active on
extern const float lbl_100_rodata_8;

extern "C" void fn_100_98CC(char* obj, int index, float divisor) {
    if (lbl_100_rodata_8 == divisor) {
        return;
    }
    float* arr = *reinterpret_cast<float**>(obj + 0x14);
    arr[index] = arr[index] / divisor;
}
