#pragma force_active on
typedef int s32;

extern s32 fn_803D9C50(s32, s32, s32, s32);

s32 fn_803DA758(s32 arg0, s32 arg1, s32 arg2)
{
    s32 result;

    result = fn_803D9C50(arg0, *(s32 *)&arg0 + 0x1634, arg1, arg2);
    return result & ((-result | result) >> 31);
}
