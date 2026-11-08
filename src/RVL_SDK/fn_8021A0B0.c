#pragma force_active on
typedef signed int s32;

extern void fn_8022550C(void *p, ...);
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32 level);
extern char lbl_8047C86C[];
extern char *lbl_804F6810[];

s32 fn_8021A0B0(s32 arg0, s32 arg1) {
    s32 old;
    s32 level;
    char *obj;

    fn_8022550C(lbl_8047C86C);
    level = OSDisableInterrupts();
    obj = lbl_804F6810[arg0];
    old = *(s32 *)(obj + 0x8A8);
    *(s32 *)(obj + 0x8A8) = arg1;
    OSRestoreInterrupts(level);
    return old;
}
