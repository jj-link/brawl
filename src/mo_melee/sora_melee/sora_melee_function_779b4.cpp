#include <types.h>
#pragma force_active on

struct fn_27_779B4_Ptr {
    s32 unk0;
    s32 val;
};

struct fn_27_779B4_Src {
    fn_27_779B4_Ptr* ptr;
    u8 flag;
};

extern "C" {
void fn_27_779B4(s32* out, fn_27_779B4_Src* src) {
    if (src->flag == 1) {
        *out = -1;
    } else {
        *out = src->ptr->val;
    }
}
}
