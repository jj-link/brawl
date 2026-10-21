#pragma force_active on
extern char lbl_804FB4A0[];
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);

void fn_8022B8BC(int a, int b) {
    int level = OSDisableInterrupts();
    *(int*)(lbl_804FB4A0 + 0x6f4) = a;
    *(int*)(lbl_804FB4A0 + 0x6f8) = b;
    OSRestoreInterrupts(level);
}
