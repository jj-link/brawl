#pragma force_active on
extern "C" void fn_117_A790(void* self, int index, float value) {
    float* arr = *(float**)((char*)self + 0x14);
    arr[index] += value;
}
