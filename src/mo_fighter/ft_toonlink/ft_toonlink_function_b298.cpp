#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_121_B298(u8* self, u32 index, float value) {
    float* arr = *(float**)(self + 0x14);
    arr[index] *= value;
}
