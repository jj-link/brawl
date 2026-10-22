#pragma force_active on
extern unsigned char lbl_8052D5A8[];
extern char lbl_804840D0[];
extern void fn_802319E4(unsigned int, const char *);
extern void fn_802516E4(void *, int);

void fn_80251224(unsigned int arg0) {
    unsigned char *p;
    int i;

    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319E4(0x90003, lbl_804840D0);
    }
    i = 0;
    p = lbl_8052D5A8 + 0x68;
    do {
        if (*(unsigned int *)(p + 0x6C) == arg0) {
            fn_802516E4(p, 0x12);
        }
        i++;
        p += 0xA4;
    } while (i < 5);
}
