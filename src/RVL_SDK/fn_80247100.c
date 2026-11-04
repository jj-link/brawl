#pragma force_active on
typedef unsigned char u8;

extern void fn_802319E4(int id, const char *msg);
extern u8 fn_80247040(u8 arg);
extern void fn_80231FB0(void *p, int a, int b);
extern char lbl_80482358[];
extern char lbl_8052C870[];

void fn_80247100(void) {
    u8 temp_r3;

    if (*(u8 *)(lbl_8052C870 + 0x141) >= 5) {
        fn_802319E4(0x1E0004, lbl_80482358);
    }
    temp_r3 = *(u8 *)(lbl_8052C870 + 0x9);
    *(u8 *)(lbl_8052C870 + 0x9) = temp_r3 + 1;
    if (fn_80247040(temp_r3) != 0) {
        if (*(u8 *)(lbl_8052C870 + 0x9) > 0xF) {
            *(u8 *)(lbl_8052C870 + 0x8) = 0;
            (*(void (**)(int, int, int))(lbl_8052C870 + 0xC4))(1, 0, 0);
            return;
        }
        fn_80231FB0(lbl_8052C870 + 0x1C, 0x16, 1);
        return;
    }
    (*(void (**)(int, int, int))(lbl_8052C870 + 0xC4))(2, *(u8 *)(lbl_8052C870 + 0x9), 0);
}
