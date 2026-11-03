#pragma force_active on
extern void fn_802319E4(unsigned int, const char *);
extern void fn_802516E4(void *, int);
extern void *fn_80251AD0(void);
extern unsigned char lbl_8052D5A8[];
extern char lbl_804840AC[];

void fn_8025111C(void) {
    void *result;
    result = fn_80251AD0();
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319E4(0x90003, lbl_804840AC);
    }
    if (result != 0) {
        fn_802516E4(result, 0x13);
    }
}