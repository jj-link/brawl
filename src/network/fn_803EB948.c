#pragma force_active on
typedef signed char s8;

void PFAPI_convertReturnValue(void);
void fn_803EA788(s8);

void fn_803EB948(s8 arg0) {
    fn_803EA788(arg0);
    PFAPI_convertReturnValue();
}
