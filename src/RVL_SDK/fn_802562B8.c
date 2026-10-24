#pragma force_active on
extern unsigned char lbl_8052D5A8[];
extern char lbl_80484B08[];
extern void fn_802319E4(int, const char *);
extern void fn_80232020(void *);
extern void fn_8022F0E0(void *);
extern void *fn_8022F77C(void *);
extern void *memset(void *, int, unsigned long);

void fn_802562B8(void *arg0) {
    char *s = arg0;
    void *p;
    if (lbl_8052D5A8[0x414] >= 4) {
        fn_802319E4(0x90003, lbl_80484B08);
    }
    fn_80232020(s);
    while ((p = fn_8022F77C(s + 0x18)) != 0) {
        fn_8022F0E0(p);
    }
    memset(s, 0, 0x78);
    s[0x6C] = 0;
}
