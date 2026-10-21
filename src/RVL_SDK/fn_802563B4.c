#pragma force_active on
extern void fn_802319E4(unsigned int, const char *);
extern void fn_80232020(void *);
extern unsigned char lbl_8052D5A8[];
extern char lbl_80484B08[];

void fn_802563B4(void *arg0) {
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319E4(0x90003, lbl_80484B08);
    }
    fn_80232020(arg0);
}
