#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);

int fn_8035D1B8(int *arg0) {
    int level;
    int v;

    level = OSDisableInterrupts();
    v = *arg0 + 1;
    *arg0 = v;
    OSRestoreInterrupts(level);
    return v;
}
