#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" s32 fn_116_AC5C();

extern "C" float fn_116_18934(u8* base, void* unused, s32 a, s32 b) {
    u8* q = base + fn_116_AC5C() * 0xa4;
    float* p = *(float**)(q + a * 4 - 0x3e70);
    return p[b];
}
