#pragma force_active on

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern int fn_801DD044(int, int);

int fn_801DD320(int arg0) {
    int mask;
    int enabled;
    int previous;
    int user;
    int pending;

    enabled = OSDisableInterrupts();
    previous = *(int *)0x800000C4;
    user = *(int *)0x800000C8;
    pending = arg0 & (previous | user);
    arg0 = previous & ~arg0;
    *(int *)0x800000C4 = arg0;
    mask = arg0 | user;

    while (pending != 0) {
        pending = fn_801DD044(pending, mask);
    }

    OSRestoreInterrupts(enabled);
    return previous;
}
