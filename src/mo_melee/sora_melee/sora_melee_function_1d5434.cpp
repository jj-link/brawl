#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
u8 fn_27_1D5434(u8* base, s32 idx, s32 off)
{
    u8* p = *(u8**)(base + idx * 4 + 0x184);
    return p[off];
}
}
