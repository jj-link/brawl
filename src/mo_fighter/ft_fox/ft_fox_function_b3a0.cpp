#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_97_B3A0(void* self, u32 index, float value) {
    float* arr = *(float**)((u8*)self + 0x14);
    arr[index] -= value;
}
