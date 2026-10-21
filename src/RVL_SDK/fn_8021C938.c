#pragma force_active on
extern int lbl_804F6810[];
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);

int fn_8021C938(int idx) {
    int *p;
    int val;
    int level;

    p = (int *)lbl_804F6810[idx];
    level = OSDisableInterrupts();
    val = *(int *)((char *)p + 0x838);
    OSRestoreInterrupts(level);
    return val;
}
