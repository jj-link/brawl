#pragma force_active on
extern int lbl_805A0FA8;

void fn_80379148(int arg);

void fn_80341454(void) {
    if (*(unsigned char *)(lbl_805A0FA8 + 0x15) == 2) {
        return;
    }
    *(unsigned char *)(lbl_805A0FA8 + 0x14) = 0;
    *(unsigned char *)(lbl_805A0FA8 + 0x18) = 0;
    fn_80379148(*(int *)(lbl_805A0FA8 + 0x10));
}
