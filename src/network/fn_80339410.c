#include <types.h>
#pragma force_active on

extern void *lbl_805A0F80;

s32 fn_80339410(void) {
    if (lbl_805A0F80 != NULL) {
        if (*(s32 *)((char *)lbl_805A0F80 + 0x4) == 5) {
            return 1;
        }
    }
    return 0;
}
