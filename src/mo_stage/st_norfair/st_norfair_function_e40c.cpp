#pragma force_active on
typedef unsigned int u32;

extern "C" float fn_54_E40C(void* self, u32 index) {
    float* arr = *(float**)((char*)self + 0x760);
    return arr[index];
}
