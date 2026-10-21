#pragma force_active on
extern int *lbl_805A1250;

int fn_803CD3F4(void) {
    if (lbl_805A1250 == 0) {
        return 0;
    }
    return *(int *)((char *)lbl_805A1250 + 0x1B48);
}
