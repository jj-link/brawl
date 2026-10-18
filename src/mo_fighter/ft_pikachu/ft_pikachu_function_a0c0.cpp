#pragma force_active on
extern "C" void fn_98_A0C0(char* self, int index, float value) {
    float* arr = *(float**)(self + 0x14);
    arr[index] += value;
}
