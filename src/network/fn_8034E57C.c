#pragma force_active on
typedef int s32;

extern void *lbl_805A0FB0;

s32 fn_8034E57C(s32 arg0) {
    if (lbl_805A0FB0 == 0) {
        return 0;
    }
    *(s32 *)((char *)lbl_805A0FB0 + 0x904) = arg0;
    return 1;
}
