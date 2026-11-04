#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_802319E4(int id, const char *msg);
extern u16 fn_8024A530(int id, void *arg);
extern char lbl_80482328[];
extern char lbl_80482340[];
extern char lbl_8052C870[];

int fn_80247040(void) {
    char *b = lbl_8052C870;
    u16 r;

    if (*(u8 *)(b + 0x141) >= 4) {
        fn_802319E4(0x1E0003, lbl_80482328);
    }
    *(u16 *)(b + 0x14) = 0;
    *(u16 *)(b + 0x16) = 0;
    *(u8 *)(b + 0x11) = 1;
    r = fn_8024A530(0x11, lbl_8052C870);
    *(u16 *)(b + 0x14) = r;
    if (r == 0) {
        if (*(u8 *)(lbl_8052C870 + 0x141) >= 2) {
            fn_802319E4(0x1E0001, lbl_80482340);
        }
        return 0xE;
    }
    *(u8 *)(b + 0x10) = 1;
    return 0;
}
