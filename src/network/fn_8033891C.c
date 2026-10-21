#pragma force_active on
typedef signed int s32;

extern void *lbl_805A0F80;

s32 fn_8033891C(void) {
    if (lbl_805A0F80 != 0) {
        return *(s32 *)((char *)lbl_805A0F80 + 0x1C);
    }
    return 0;
}
