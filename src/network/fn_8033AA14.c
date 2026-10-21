#include <types.h>
#pragma force_active on

extern void *lbl_805A0F88;

u8 fn_8033AA14(void) {
    s32 r;

    if (lbl_805A0F88 == NULL || (r = *(s32 *)((char *)lbl_805A0F88 + 0x514), r == 0) || r == 9 || r == 10 || r == 11 || *(u8 *)((char *)lbl_805A0F88 + 0x36F) == 0 || *(u8 *)((char *)lbl_805A0F88 + 0x377) == 0) {
        return 0xFF;
    }
    return *(u8 *)((char *)lbl_805A0F88 + 0x648);
}
