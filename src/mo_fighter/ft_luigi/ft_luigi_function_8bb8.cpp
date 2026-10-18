#pragma force_active on
extern "C" void fn_99_8BB8(unsigned char* self, int scale, unsigned int index) {
    int* arr = *(int**)(self + 0xc);
    arr[index] *= scale;
}
