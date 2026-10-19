#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" s32 fn_104_AE30();

extern "C" s32 fn_104_1BAD0(u8* base, s32 unused, s32 i, s32 j) {
    s32 t = *(s32*)((u8*)base - 0x10000 + fn_104_AE30() * 0x28 + i * 4 - 0x75f8);
    return ((s32*)t)[j];
}
