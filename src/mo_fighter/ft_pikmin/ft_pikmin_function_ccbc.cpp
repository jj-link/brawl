#pragma force_active on
extern "C" void fn_113_CCBC(unsigned char* self, unsigned int index, float scale) {
    float* arr = *(float**)(self + 0x14);
    arr[index] *= scale;
}
