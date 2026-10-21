#pragma force_active on

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern void fn_801E0A80(int);

void fn_801E0CC0(void) {
    int temp_r31;

    temp_r31 = OSDisableInterrupts();
    fn_801E0A80(1);
    OSRestoreInterrupts(temp_r31);
}
