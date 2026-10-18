#pragma force_active on
extern "C" void fn_109_931C(unsigned char* self, int value, unsigned int index) {
    int* arr = *(int**)(self + 0xc);
    arr[index] *= value;
}
