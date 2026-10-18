#pragma force_active on
extern "C" void fn_101_D424(void* self, int index, float value) {
    float* arr = *reinterpret_cast<float**>(reinterpret_cast<unsigned char*>(self) + 0x14);
    arr[index] += value;
}
