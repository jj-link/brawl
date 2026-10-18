#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_125_B2A0(void* self, u32 index, float scale) {
    float* arr = *(float**)((char*)self + 0x14);
    arr[index] *= scale;
}
