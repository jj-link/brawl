#pragma force_active on
extern unsigned char lbl_8052D5A8[];
extern char lbl_804842C8[];
extern void fn_802319E4(unsigned int, const char *);
extern void fn_802564E4(unsigned char *);
extern void fn_8025648C(void *);
extern void fn_8022F0E0(void *);
extern void *fn_8022F77C(void *);
extern void *memset(void *, int, unsigned long);

void fn_802519F4(void *arg0) {
    unsigned char *s = (unsigned char*)arg0;
    void *p;

    while ((p = fn_8022F77C(s + 0x30)) != 0) {
        fn_8022F0E0(p);
    }
    *(int*)(s + 0x40) = 0;

    while ((p = fn_8022F77C(s + 0x18)) != 0) {
        fn_8022F0E0(p);
    }

    *(int*)(s + 0x28) = 0;
    s[2] = 0;

    if (s[0x68] == 0) {
        if (lbl_8052D5A8[0x414] >= 5) {
            fn_802319E4(0x90004, lbl_804842C8);
        }
        if (*(int*)(s + 0x6c) != 0) {
            *(unsigned char*)(*(int*)(s + 0x6c) + s[0xd] + 0x24) = 0;
            fn_802564E4((unsigned char*)(*(int*)(s + 0x6c)));
        }
        fn_8025648C(s);
        memset(s, 0, 0xa4);
    }
}