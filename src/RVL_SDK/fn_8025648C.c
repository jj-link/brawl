#pragma force_active on
extern unsigned char lbl_8052D5A8[];
extern char lbl_80484B5C[];
extern void fn_802319E4(unsigned int, const char*);
extern void fn_80232020(void*);

void fn_8025648C(char* arg0) {
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319E4(0x90003, lbl_80484B5C);
    }
    fn_80232020(arg0 + 0x70);
}
