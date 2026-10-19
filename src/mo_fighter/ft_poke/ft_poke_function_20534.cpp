#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" s32 fn_116_AC5C();

extern "C" s32 fn_116_20534(u8* self, void* unused, s32 a, s32 b) {
    s32* p = *(s32**)(self - 0x10000 + fn_116_AC5C() * 0x14 + a * 4 - 0x7698);
    return p[b];
}
