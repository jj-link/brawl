#pragma force_active on
extern void SOClose(int);
extern void fn_80390948(void);
extern void fn_803909E8(void *, void *);
extern void fn_80390A64(void *, int);
extern void fn_80391AE4(void *);
extern int fn_8039716C(void);
extern void *fn_803974FC(void);
extern void *fn_80397564(void);
extern void *fn_80397578(void *);
extern void fn_803F861C(const char *, ...);
extern char lbl_80491570[];

void fn_8039028C(void *arg0, void (*arg1)(void)) {
    char *a = fn_80397564();
    void *b = fn_80397578(arg0);
    void *c;
    int r;
    fn_80390A64(b, 1);
    fn_80391AE4(arg0);
    fn_803909E8(b, a);
    c = *(void **)(a + 0x7e0);
    {
        void (*f)(void *) = *(void (**)(void *))((char *)fn_803974FC() + 0x7c8);
        if (f != 0) {
            f(c);
        }
    }
    *(int *)(a + 0x7e0) = 0;
    fn_80390948();
    *(int *)(a + 0x7cc) = 0;
    if (arg1 != 0) {
        arg1();
    }
    r = fn_8039716C();
    if (r != 0) {
        fn_803F861C(lbl_80491570, r);
    }
    if (*(int *)(a + 0x7d0) >= 0) {
        SOClose(*(int *)(a + 0x7d0));
        *(int *)(a + 0x7d0) = -1;
    }
}
