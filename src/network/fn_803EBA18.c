#pragma force_active on
typedef int s32;
typedef signed char s8;

s32 fn_803EAAE4(s32 arg0);
s32 fn_803EB504(s32 arg0);

s32 fn_803EBA18(s8 arg0) {
    s32 result = fn_803EAAE4(arg0);
    return fn_803EB504(result);
}
