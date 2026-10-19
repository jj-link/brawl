#pragma force_active on
extern const float lbl_98_rodata_8;

extern "C" void fn_98_A068(char* obj, int index, float divisor) {
    if (lbl_98_rodata_8 == divisor) return;
    float* arr = *(float**)(obj + 0x14);
    arr[index] = arr[index] / divisor;
}
