#pragma force_active on
extern void *lbl_805A0F70;

int fn_803369C0(void) {
    if (lbl_805A0F70 != 0) {
        unsigned char v = *((unsigned char *)lbl_805A0F70 + 0x22);
        if ((unsigned char)(v + 0xFF) <= 1U) {
            return 0;
        }
    }
    return 1;
}
