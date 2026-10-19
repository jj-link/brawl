#pragma force_active on
extern "C" const float lbl_91_rodata_8;

extern "C" void fn_91_A7D0(void* self, int index, float divisor) {
    if (lbl_91_rodata_8 == divisor) return;
    float* arr = *(float**)((unsigned char*)self + 0x14);
    arr[index] = arr[index] / divisor;
}
