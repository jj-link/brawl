#pragma force_active on
extern char lbl_8048DC08[];

int fn_80355454(int *arg0) {
    char *p = lbl_8048DC08;
    *arg0 = *(int *)(p + 0x6C);
    return *(int *)(p + 0x68);
}
