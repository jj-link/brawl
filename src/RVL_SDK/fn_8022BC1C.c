#pragma force_active on
typedef signed int s32;

extern void fn_8022E928(const char* fmt, ...);
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32 level);
extern char lbl_8047ED34[];
extern char lbl_804FB4A0[];

s32 fn_8022BC1C(s32 arg0) {
    s32 old;
    s32 level;

    fn_8022E928(lbl_8047ED34);
    level = OSDisableInterrupts();
    old = *(s32*)(lbl_804FB4A0 + 4);
    *(s32*)(lbl_804FB4A0 + 4) = arg0;
    OSRestoreInterrupts(level);
    return old;
}
