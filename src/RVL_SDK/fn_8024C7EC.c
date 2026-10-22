#pragma force_active on
extern char lbl_80529CF8[];
extern void *fn_8024E7C4();
extern void fn_8024AED0(void *, int, void *);
extern void fn_8023EED0(void *);
extern void fn_8024E63C(void *);
extern int fn_802502B4(int);
extern void fn_802500CC(void);

int fn_8024C7EC(void *unused, unsigned char arg1) {
    unsigned char sp8;
    char *p;
    char *n;
    int r = 1;
    sp8 = arg1;
    p = fn_8024E7C4();
    if (p == 0) {
        r = 0;
    } else {
        if (*(unsigned char *)(lbl_80529CF8 + 0x27BF) != 0xE) {
            *(unsigned char *)(lbl_80529CF8 + 0x27BF) = sp8;
        }
        for (n = *(char **)(p + 8); n != 0; ) {
            char *next = *(char **)(n + 8);
            fn_8024AED0(n, 3, &sp8);
            n = next;
        }
        fn_8023EED0(p + 0x2A);
        fn_8024E63C(p);
    }
    if (fn_802502B4(1) != 0) {
        fn_802500CC();
    }
    return r;
}
