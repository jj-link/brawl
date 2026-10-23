#pragma force_active on
extern char lbl_8048DC08[];
extern void fn_803360BC(int);

void fn_80355388(void) {
    int val = *(int *)(lbl_8048DC08 + 8);
    if (val >= 0) {
        fn_803360BC(val);
    }
    *(int *)lbl_8048DC08 = 0;
}
