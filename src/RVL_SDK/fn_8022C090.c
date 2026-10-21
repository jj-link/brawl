#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);
extern char lbl_804FB4A0[];
extern void fn_80234C5C(int a, int b);

void fn_8022C090(int arg0, int arg1) {
    int level = OSDisableInterrupts();
    lbl_804FB4A0[0x6eb] = arg0;
    lbl_804FB4A0[0x6ea] = arg1;
    OSRestoreInterrupts(level);
    fn_80234C5C(arg0, arg1);
}
