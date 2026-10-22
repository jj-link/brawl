#pragma force_active on
typedef int s32;

extern s32 fn_803D9590(s32, s32, s32, s32, s32);

s32 fn_803DA5EC(s32 arg0, s32 arg1, s32 arg2) {
    s32 r = fn_803D9590(arg0, *(s32 *)&arg0 + 0x1630, arg1, arg2, 0);
    return r & ((-r | r) >> 31);
}
