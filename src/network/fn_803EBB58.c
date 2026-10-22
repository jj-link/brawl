#pragma force_active on
extern int lbl_805A1260;
extern void fn_803EC394(int);
extern void fn_803EC418(int, void *);

int fn_803EBB58(char *arg0) {
    char *r4;
    char *r3;

    r4 = *(char **)(arg0 + 8);
    fn_803EC418(*(int *)(r4 + 0x288), r4);
    r3 = *(char **)(arg0 + 8);
    if (*(unsigned short *)(r3 + 0x27E) == 0 && *(int *)(r3 + 0x280) == 0 && lbl_805A1260 != 0) {
        fn_803EC394(*(int *)(r3 + 0x288));
        *(int *)(*(char **)(arg0 + 8) + 0x288) = 0;
        lbl_805A1260 = lbl_805A1260 - 1;
    }
    return 0;
}
