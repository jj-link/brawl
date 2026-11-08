#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 lbl_8052C9B8[];
extern char lbl_80482378[];
extern u8 fn_8023F558(int, char *, u8, int, u16, u32, int);
extern void fn_802319E4(int, const char *);

int fn_8024809C(char *arg0, int arg1) {
    char *s = lbl_80482378;
    if (fn_8023F558(0, arg0, 0x20, arg1, 0x11, 6, 1) == 0) {
        if (lbl_8052C9B8[0x401] >= 1U) fn_802319E4(0x1e0000, s + 0x54);
        return 3;
    }
    if (fn_8023F558(1, arg0, 0x20, arg1, 0x11, 6, 1) == 0) {
        if (lbl_8052C9B8[0x401] >= 1U) fn_802319E4(0x1e0000, s + 0x74);
        return 3;
    }
    if (fn_8023F558(0, arg0, 0x21, 0, 0x11, 6, 2) == 0) {
        if (lbl_8052C9B8[0x401] >= 1U) fn_802319E4(0x1e0000, s + 0x94);
        return 3;
    }
    if (fn_8023F558(1, arg0, 0x21, 0, 0x11, 6, 2) == 0) {
        if (lbl_8052C9B8[0x401] >= 1U) fn_802319E4(0x1e0000, s + 0xb4);
        return 3;
    }
    if (fn_8023F558(1, arg0, 0x22, 0, 0x13, 6, 0) == 0) {
        if (lbl_8052C9B8[0x401] >= 1U) fn_802319E4(0x1e0000, s + 0xd4);
        return 3;
    }
    if (fn_8023F558(0, arg0, 0x22, 0, 0x13, 6, 0) == 0) {
        if (lbl_8052C9B8[0x401] >= 1U) fn_802319E4(0x1e0000, s + 0xf4);
        return 3;
    }
    return 0;
}