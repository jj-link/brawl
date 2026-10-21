#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);
extern char lbl_804FB4A0[];

s8 fn_8022BB2C(void) {
    u8 v;
    int level = OSDisableInterrupts();
    v = lbl_804FB4A0[0x708];
    OSRestoreInterrupts(level);
    return (s8)v;
}
