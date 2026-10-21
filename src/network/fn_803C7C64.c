#pragma force_active on
extern unsigned int fn_803C43AC(void);
extern char lbl_80563590[];

int fn_803C7C64(void) {
    int *temp;
    unsigned int idx;

    idx = fn_803C43AC();
    if (idx < 0x1A) {
        temp = (int *)(lbl_80563590 + idx * 0x14);
    } else {
        temp = 0;
    }
    if (temp != 0) {
        return *temp;
    }
    return 0;
}
