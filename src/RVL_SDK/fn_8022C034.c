#pragma force_active on
typedef signed int s32;

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);
extern void fn_8022E928(const char* fmt, ...);
extern char lbl_8047EE50[];
extern char lbl_804FB4A0[];

s32 fn_8022C034(s32 arg0) {
    s32 old;
    s32 level;

    fn_8022E928(lbl_8047EE50);
    level = OSDisableInterrupts();
    old = *(s32*)(lbl_804FB4A0 + 0x6F0);
    *(s32*)(lbl_804FB4A0 + 0x6F0) = arg0;
    OSRestoreInterrupts(level);
    return old;
}
