#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);
extern int lbl_805A0C74;

void fn_8021A624(int arg0) {
    int level = OSDisableInterrupts();
    lbl_805A0C74 = arg0;
    OSRestoreInterrupts(level);
}
