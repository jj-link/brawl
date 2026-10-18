#pragma force_active on
extern "C" void fn_100_990C(char* self, int index, float value) {
    float* arr = *reinterpret_cast<float**>(self + 0x14);
    arr[index] = arr[index] - value;
}
