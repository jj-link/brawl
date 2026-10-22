#pragma force_active on
extern void fn_802319E4(unsigned int, const char *);
extern void fn_80254568(void *, short);
extern unsigned char lbl_8052D5A8[];
extern const char lbl_80483F08[];

void fn_802505DC(void *arg0) {
    unsigned char *p;
    int i;

    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319E4(0x90003, lbl_80483F08);
    }
    p = lbl_8052D5A8 + 0x68;
    for (i = 5; i != 0; i--) {
        void *t = *(void **)(p + 0x6C);
        if (t == 0 || t == arg0) {
            fn_80254568(arg0, 0);
            return;
        }
        p += 0xA4;
    }
    fn_80254568(arg0, 1);
}
