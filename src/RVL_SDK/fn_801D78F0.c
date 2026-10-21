#pragma force_active on
typedef int s32;

s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(s32);
void fn_801D7824(void);

void fn_801D78F0(void) {
    s32 state;
    state = OSDisableInterrupts();
    fn_801D7824();
    OSRestoreInterrupts(state);
}
