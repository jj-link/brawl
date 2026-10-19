#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" s32 fn_104_AE30();

extern "C" s32 fn_104_AE3C(s32 a, s32 unused, s32 b, s32 c) {
    u8* base = (u8*)a;
    s32* tbl = *(s32**)(base - 0x10000 + fn_104_AE30() * 0x1c + b * 4 - 0x75f0);
    return tbl[c];
}
