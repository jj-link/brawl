#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern void fn_802319E4(u32, const char *);
extern void fn_802516E4(void *, int);
extern void fn_802562B8(u32);
extern unsigned char lbl_804840C0[];
extern unsigned char lbl_8052D5A8[];

void fn_80251184(u32 arg0) {
    u8 *p;
    s32 i;

    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319E4(0x90003, (const char *)lbl_804840C0);
    }
    i = 0;
    p = lbl_8052D5A8 + 0x68;
    do {
        if (*(u32 *)(p + 0x6C) == arg0) {
            fn_802516E4(p, 0x10);
        }
        i++;
        p += 0xA4;
    } while (i < 5);
    fn_802562B8(arg0);
}
