#pragma force_active on
extern char *lbl_805A0E98;

void fn_8027AF80(void) {
    char *p = lbl_805A0E98;
    *(int *)(p + 0x58) = -1;
    *(int *)(p + 0x50) = 0;
    *(int *)(p + 0xC0) = -1;
    *(int *)(p + 0xB8) = 0;
    *(int *)(p + 0x128) = -1;
    *(int *)(p + 0x120) = 0;
    *(int *)(p + 0x190) = -1;
    *(int *)(p + 0x188) = 0;
}
