#include <revolution/VF/pf_str.h>
#include <revolution/types.h>
#pragma force_active on

extern s32 fn_803E55A8(PF_STR*);
extern int lbl_805644C0[];
extern int PFAPI_convertReturnValue(int);

int fn_803EB9C8(const char* arg) {
    PF_STR sp8;
    s32 result = PFSTR_InitStr(&sp8, arg, 1);
    if (result == 0) {
        result = fn_803E55A8(&sp8);
    } else {
        lbl_805644C0[0x10] = result;
    }
    return PFAPI_convertReturnValue(result);
}
