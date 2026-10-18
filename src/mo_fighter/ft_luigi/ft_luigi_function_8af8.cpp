#pragma force_active on
extern "C" void fn_99_8AF8(unsigned char* self, int idx, float scale) {
    float* arr = *(float**)(self + 0x14);
    arr[idx] *= scale;
}
