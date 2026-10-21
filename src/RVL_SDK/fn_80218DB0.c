#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern unsigned char lbl_805A0C78;

unsigned char fn_80218DB0(void) {
    unsigned char temp_r31;

    OSDisableInterrupts();
    temp_r31 = lbl_805A0C78;
    OSRestoreInterrupts();
    return temp_r31;
}
