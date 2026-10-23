#pragma force_active on
typedef int s32;

extern s32 fn_803AF38C(s32, s32, s32, s32);

s32 fn_803B0048(s32 arg0, s32 arg1, s32 arg2)
{
    s32 result = fn_803AF38C(arg0, *(s32 *)&arg0 + 0x15F8, arg1, arg2);
    return result & ((-result | result) >> 31);
}
