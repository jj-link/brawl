#pragma force_active on
extern void (*lbl_805A09A8)(void);
extern void fn_801FC3A0(void);
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);

int fn_801FC454(int arg) {
    int old = OSDisableInterrupts();
    int result = (lbl_805A09A8 != 0);
    if (arg) {
        lbl_805A09A8 = fn_801FC3A0;
    } else {
        lbl_805A09A8 = 0;
    }
    OSRestoreInterrupts(old);
    return result;
}
