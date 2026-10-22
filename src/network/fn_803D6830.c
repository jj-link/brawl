#include <revolution/types.h>
#include <revolution/VF/pf_str.h>
#pragma force_active on

extern s32 fn_803D643C(char* a);
extern s32 fn_803D6504(u16* a);

s32 PFSTR_InitStr(PF_STR* str, const char* s, u32 mode) {
    if (mode == 1) {
        str->head = s;
        str->tail = s + fn_803D643C((char*)s);
    } else if (mode == 2) {
        str->head = s;
        str->tail = s + fn_803D6504((u16*)s) * 2;
    }
    str->mode = mode;
    return 0;
}
