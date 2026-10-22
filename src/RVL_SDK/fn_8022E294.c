#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);
extern unsigned short lbl_804FD428[16];

int fn_8022E294(signed char idx) {
    int level;
    int result;

    level = OSDisableInterrupts();
    if (idx >= 0 && idx < 16) {
        result = lbl_804FD428[idx];
    } else {
        result = 0;
    }
    OSRestoreInterrupts(level);
    return result;
}
