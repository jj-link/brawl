#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" s32 fn_120_9E7C();

extern "C" float fn_120_9E24(u8* base, s32 unused, s32 i, s32 j) {
    u8* p = base + fn_120_9E7C() * 0xD8;
    float* arr = *(float**)(p + i * 4 - 0x3E70);
    return arr[j];
}
