#pragma force_active on
extern void fn_80335450(int a, int b, int c);
extern void fn_803355A4(void *p);
extern void fn_803359CC(void);
extern char lbl_8048DC08[];

void fn_803553C8(void) {
    int a;
    int c;
    a = *(int *)(lbl_8048DC08 + 0x54);
    if (a) {
        fn_80335450(8, a, 0);
        *(int *)(lbl_8048DC08 + 0x54) = 0;
    }
    c = *(int *)(lbl_8048DC08 + 0x60);
    if (c) {
        fn_803355A4((void *)c);
        *(int *)(lbl_8048DC08 + 0x64) = 0;
        *(int *)(lbl_8048DC08 + 0x60) = 0;
    }
    fn_803359CC();
    *(int *)(lbl_8048DC08 + 0) = 2;
    *(int *)(lbl_8048DC08 + 0x4) = 0;
}
