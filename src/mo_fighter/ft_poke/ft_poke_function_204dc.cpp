#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" s32 fn_116_AC5C();

extern "C" float fn_116_204DC(u8* self, void* unused, s32 i, s32 j) {
    s32 k = fn_116_AC5C();
    float** tbl = (float**)(self + k * 0x2c - 0x3e70);
    return tbl[i][j];
}
