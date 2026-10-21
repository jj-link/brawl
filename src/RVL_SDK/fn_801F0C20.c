#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);
extern int lbl_805A08C8;

int fn_801F0C20(int arg0) {
    int temp_r31;
    int level;

    temp_r31 = lbl_805A08C8;
    level = OSDisableInterrupts();
    lbl_805A08C8 = arg0;
    OSRestoreInterrupts(level);
    return temp_r31;
}
