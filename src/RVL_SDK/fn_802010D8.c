#pragma force_active on
extern int lbl_805A0AC4;
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);

int fn_802010D8(int arg0) {
    int old;
    int level;

    old = lbl_805A0AC4;
    level = OSDisableInterrupts();
    lbl_805A0AC4 = arg0;
    OSRestoreInterrupts(level);
    return old;
}
