#pragma force_active on
extern "C" void fn_99_8B28(float* const* self, int index, float value) {
    float* arr = *(float**)((char*)self + 0x14);
    float cur = arr[index];
    arr[index] = cur + value;
}
