#pragma force_active on
extern unsigned int fn_803C43AC();
extern char lbl_80563590[];

void fn_803C7DE8(void *unused, int value) {
    char *temp_r3;
    unsigned int idx;

    idx = fn_803C43AC();
    if (idx < 0x1A) {
        temp_r3 = lbl_80563590 + idx * 0x14;
    } else {
        temp_r3 = 0;
    }
    if (temp_r3 != 0) {
        *(int *)(temp_r3 + 8) = value;
    }
}
