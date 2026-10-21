#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 level);
extern s32 lbl_805A0A18;

s32 fn_801FEBC0(s32 arg0) {
    s32 old;
    u32 level;

    old = lbl_805A0A18;
    level = OSDisableInterrupts();
    lbl_805A0A18 = arg0;
    OSRestoreInterrupts(level);
    return old;
}
