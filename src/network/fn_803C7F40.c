#pragma force_active on
extern unsigned int fn_803C43AC(void);
extern char lbl_80563590[];

void fn_803C7F40(void *unused, int value) {
    char *p;
    unsigned int idx;

    idx = fn_803C43AC();
    if (idx < 0x1A) {
        p = lbl_80563590 + idx * 0x14;
    } else {
        p = 0;
    }
    if (p != 0) {
        *(int *)(p + 0x10) = value;
    }
}
