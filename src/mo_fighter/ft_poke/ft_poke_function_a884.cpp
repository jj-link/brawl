#pragma force_active on
extern "C" void fn_116_A884(char* self, unsigned int index, float value) {
    float* arr = *(float**)(self + 0x14);
    arr[index] -= value;
}
