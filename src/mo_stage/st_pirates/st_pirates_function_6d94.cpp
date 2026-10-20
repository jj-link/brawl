#pragma force_active on
typedef unsigned int u32;

extern "C" float fn_52_6D94(const void* work, u32 index) {
    float* arr = *(float**)((char*)work + 0x520);
    return arr[index];
}
