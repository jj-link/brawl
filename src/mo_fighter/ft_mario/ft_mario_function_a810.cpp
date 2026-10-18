#pragma force_active on
extern "C" {
void fn_91_A810(void* self, int index, float value) {
    float* arr = *reinterpret_cast<float**>(static_cast<unsigned char*>(self) + 0x14);
    arr[index] -= value;
}
}
