#pragma force_active on
extern int lbl_805A0E80;

int fn_8026F834(void) {
    char *obj = (char *)lbl_805A0E80;
    if (*(int *)(obj + 0x10) != 0x12) {
        return -1;
    }
    return *(int *)(obj + 0xB0);
}
