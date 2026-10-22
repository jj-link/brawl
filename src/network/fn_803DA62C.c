#pragma force_active on
typedef int s32;

extern s32 fn_803D9590(s32, s32, s32, s32, s32);

s32 fn_803DA62C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    temp_r3 = fn_803D9590(arg0, *(s32 *)&arg0 + 0x1634, arg1, arg2, arg3);
    return temp_r3 & ((-temp_r3 | temp_r3) >> 0x1F);
}
