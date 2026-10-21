#pragma force_active on
extern unsigned char lbl_805A1258;
extern void *lbl_805A1250;

int fn_803CD458(void) {
    unsigned char *ptr = &lbl_805A1258;
    if (lbl_805A1250 != 0) {
        ptr = (unsigned char *)lbl_805A1250 + 0x1B3C;
    }
    return (*ptr >> 1) & 1;
}
