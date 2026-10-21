#pragma force_active on
extern int lbl_805A0FA8;

int fn_80342244(int *arg0) {
    if (lbl_805A0FA8 == 0) {
        return 0;
    }
    *arg0 = lbl_805A0FA8 + 0x2E8;
    return *(unsigned char *)(lbl_805A0FA8 + 0xD) + 1;
}
