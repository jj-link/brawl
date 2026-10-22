#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern void fn_8025FFB8(void);
extern int lbl_805A0E68;
extern unsigned char lbl_805A0E70;

void fn_8025F9E4(void **arg0, int arg1) {
    int temp_r31;

    temp_r31 = OSDisableInterrupts();
    *arg0 = &lbl_805A0E70;
    lbl_805A0E68 = arg1;
    fn_8025FFB8();
    OSRestoreInterrupts(temp_r31);
}
