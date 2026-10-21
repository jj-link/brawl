#pragma force_active on
typedef signed char s8;
typedef int s32;

extern s32 fn_803EAE34(s8 arg0, s32 *out);
extern s32 PFAPI_convertReturnValue(void);

s32 fn_803EB8B4(s8 arg0) {
    s32 sp8;

    sp8 = 0;
    if (fn_803EAE34(arg0, &sp8) == 0) {
        return sp8;
    }
    return PFAPI_convertReturnValue();
}
