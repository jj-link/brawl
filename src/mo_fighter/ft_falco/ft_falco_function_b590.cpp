#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" s32 fn_108_B5E8();

extern "C" float fn_108_B590(u8* base, void* unused, s32 i, s32 j) {
    u8* p = base + fn_108_B5E8() * 0x70;
    float* tbl = *(float**)(p + i * 4 - 0x3E70);
    return tbl[j];
}
