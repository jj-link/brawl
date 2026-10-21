#pragma force_active on
typedef int s32;

extern s32 fn_803E3610(void);
extern void fn_803EBBD8(void);
extern void PFAPI_convertReturnValue(s32);

void fn_803EB874(void) {
    s32 temp_r3;

    temp_r3 = fn_803E3610();
    if (temp_r3 == 0) {
        fn_803EBBD8();
    }
    PFAPI_convertReturnValue(temp_r3);
}
