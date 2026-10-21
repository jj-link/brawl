#pragma force_active on

extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int status);
extern unsigned int lbl_804E43F0[6];

int fn_801FB80C(void) {
    int enabled;
    unsigned int *ptr;
    int i;

    enabled = OSDisableInterrupts();
    ptr = lbl_804E43F0;
    for (i = 0; i < 4; i++) {
        if (*ptr != (unsigned int)ptr) {
            OSRestoreInterrupts(enabled);
            return 1;
        }
        ptr += 2;
    }
    OSRestoreInterrupts(enabled);
    return 0;
}
