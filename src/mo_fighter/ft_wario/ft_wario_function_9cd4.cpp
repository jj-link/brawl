#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" s32 fn_110_9CC8();

extern "C" s32 fn_110_9CD4(u8* base, s32 unused, s32 i, s32 j) {
    u8* p = (base - 0x10000) + fn_110_9CC8() * 0x20;
    p = p + i * 4;
    s32* tbl = *(s32**)(p - 0x7620);
    return tbl[j];
}
