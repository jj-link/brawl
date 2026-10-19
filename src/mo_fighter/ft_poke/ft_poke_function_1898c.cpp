#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" s32 fn_116_AC5C();

extern "C" s32 fn_116_1898C(u8* base, s32 unused, s32 a, s32 b) {
    u8* p = (base - 0x10000) + fn_116_AC5C() * 0x18;
    p = p + a * 4;
    s32* arr = *(s32**)(p - 0x75a8);
    return arr[b];
}
