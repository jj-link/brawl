#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern void fn_802319FC(int, const char *, int);
extern void fn_8024AA7C(u16);
extern void fn_8025AFE8(void *);
extern u8 lbl_8052D9C0[];
extern char lbl_80484F9C[];

void fn_80259FF4(u8 *arg0, s16 arg1) {
    void (*temp_r12)(s16);

    if (lbl_8052D9C0[0x4630] >= 4U) {
        fn_802319FC(0xA0003, lbl_80484F9C, *(u16 *)(arg0 + 0x22));
    }
    if (arg0[0] != 1U) {
        fn_8024AA7C(*(u16 *)(arg0 + 0x22));
        *(s16 *)(arg0 + 0x472) = arg1;
        return;
    }
    temp_r12 = *(void (**)(s16))(arg0 + 0x414);
    if (temp_r12 != 0) {
        temp_r12(arg1);
    }
    fn_8025AFE8(arg0);
}
