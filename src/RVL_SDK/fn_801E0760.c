#pragma force_active on
typedef signed int s32;

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32 level);
extern s32 lbl_805A06F0;

s32 fn_801E0760(void) {
    s32 level;
    s32 temp_r31;

    level = OSDisableInterrupts();
    temp_r31 = lbl_805A06F0;
    lbl_805A06F0 = temp_r31 + 1;
    OSRestoreInterrupts(level);
    return temp_r31;
}
