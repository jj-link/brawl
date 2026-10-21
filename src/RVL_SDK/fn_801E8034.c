#pragma force_active on
extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(void);
extern int lbl_805A0820;

int fn_801E8034(int arg0) {
    int temp_r31;

    temp_r31 = lbl_805A0820;
    OSDisableInterrupts();
    lbl_805A0820 = arg0;
    OSRestoreInterrupts();
    return temp_r31;
}
