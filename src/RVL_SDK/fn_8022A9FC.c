#pragma force_active on
extern char lbl_804FB4A0[];
void OSDisableInterrupts(void);
void OSRestoreInterrupts(void);
void fn_8022C824(void*);

int fn_8022A9FC(void) {
    unsigned char t;
    int i;
    char* p;
    char* b = lbl_804FB4A0;
    OSDisableInterrupts();
    t = b[0x6E5];
    OSRestoreInterrupts();
    if (t != 0) return 3;
    p = b + 0xE4;
    for (i = 0; i < 10; i++, p += 0x60) {
        if (*(unsigned char*)(p + 0x59) == 1) fn_8022C824(p + 0x40);
    }
    p = b + 0x4A4;
    for (i = 0; i < 6; i++, p += 0x60) {
        if (*(unsigned char*)(p + 0x59) == 1) fn_8022C824(p + 0x40);
    }
    return 5;
}
