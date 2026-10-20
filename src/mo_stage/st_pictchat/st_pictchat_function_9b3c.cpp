#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" float fn_73_9B3C(const u8* self, u32 index) {
    float* arr = *(float**)(self + 0x5ac);
    return arr[index];
}
