#pragma force_active on
#include <revolution/VF/pf_str.h>
#include <revolution/VF/pf_api_util.h>

extern int fn_803DC468(PF_STR*);
extern int lbl_805644C0[];

int fn_803EB8F8(const char* arg0) {
    PF_STR sp8;
    s32 v = PFSTR_InitStr(&sp8, arg0, 1);
    if (v == 0)
        v = fn_803DC468(&sp8);
    else
        lbl_805644C0[0x10] = v;
    return PFAPI_convertReturnValue(v);
}
