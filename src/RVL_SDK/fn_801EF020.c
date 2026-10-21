#pragma force_active on
typedef signed int s32;

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32 level);
extern s32 lbl_805A08A4;

s32 fn_801EF020(s32 arg0) {
    s32 old;
    s32 level;

    old = lbl_805A08A4;
    level = OSDisableInterrupts();
    lbl_805A08A4 = arg0;
    OSRestoreInterrupts(level);
    return old;
}
