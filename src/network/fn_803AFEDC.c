#pragma force_active on
typedef int s32;
extern s32 fn_803AEC90(s32, s32, s32, s32, s32);
s32 fn_803AFEDC(s32 arg0, s32 arg1, s32 arg2) {
    s32 result = fn_803AEC90(arg0, *(s32 *)&arg0 + 0x15F4, arg1, arg2, 0);
    return result & ((-result | result) >> 31);
}
