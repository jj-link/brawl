#pragma force_active on
extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int);
extern unsigned int lbl_804E43F0[];

unsigned int fn_801FB864(void) {
    int enabled;
    unsigned int *ptr;
    unsigned int node;
    int i;
    enabled = OSDisableInterrupts();
    ptr = lbl_804E43F0;
    for (i = 0; i < 4; i++) {
        node = *ptr;
        if (node != (unsigned int)ptr) {
            OSRestoreInterrupts(enabled);
            return node;
        }
        ptr += 2;
    }
    OSRestoreInterrupts(enabled);
    return 0;
}