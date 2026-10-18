#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_107_C5A8(void* work, u32 index, float value) {
    float* arr = *(float**)((char*)work + 0x14);
    arr[index] *= value;
}
