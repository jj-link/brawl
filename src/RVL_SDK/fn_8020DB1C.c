#pragma force_active on
typedef signed int s32;

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern s32 lbl_8059EB78;

s32 fn_8020DB1C(void) {
    s32 var_r31;

    OSDisableInterrupts();
    if (lbl_8059EB78 == -0xFF) {
        var_r31 = 0;
        lbl_8059EB78 = -0xFE;
    } else {
        var_r31 = 1;
    }
    OSRestoreInterrupts();
    return var_r31 == 0;
}
