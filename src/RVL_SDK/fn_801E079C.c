#pragma force_active on
typedef signed long s32;
typedef unsigned char BOOL;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(void);
extern s32 lbl_805A06F0;

s32 OSEnableScheduler(void) {
    s32 temp;

    OSDisableInterrupts();
    temp = lbl_805A06F0;
    lbl_805A06F0 = temp - 1;
    OSRestoreInterrupts();
    return temp;
}
