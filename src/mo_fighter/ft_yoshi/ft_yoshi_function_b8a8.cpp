#pragma force_active on
extern "C" void fn_95_B8A8(char* self, unsigned int index, float value) {
    float* arr = *(float**)(self + 0x14);
    arr[index] = arr[index] - value;
}
