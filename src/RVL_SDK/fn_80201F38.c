#pragma force_active on

typedef int s32;

extern s32 lbl_805A0B28;
extern s32 lbl_805A0B2C;
extern s32 lbl_805A0B30;
extern s32 lbl_805A0B34;

void fn_80201F7C(s32);

void fn_80201F38(unsigned int arg0, s32 arg1) {
    s32 ptr;
    s32 off;
    if (arg0 > 0x60) {
        return;
    }
    if (arg1 == 0 || (arg1 & 0x1F) != 0) {
        return;
    }
    off = arg0 << 6;
    lbl_805A0B34 = arg0;
    ptr = arg1 + arg0 * 0x140;
    lbl_805A0B28 = arg1;
    lbl_805A0B2C = ptr;
    ptr = ptr + off;
    lbl_805A0B30 = ptr;
    fn_80201F7C(ptr);
}
