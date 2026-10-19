#pragma force_active on
extern "C" const float lbl_99_rodata_8;

extern "C" void fn_99_8AD0(void* obj, int idx, float divisor) {
    if (lbl_99_rodata_8 == divisor) {
        return;
    }
    float* arr = *(float**)((char*)obj + 0x14);
    arr[idx] /= divisor;
}
