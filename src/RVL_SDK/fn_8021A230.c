#pragma force_active on
extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern int fn_8021DC5C(char *, unsigned int, unsigned char, int);
extern char *lbl_804F6810[];

int fn_8021A230(int arg0, unsigned int arg1) {
    char *base;
    int r30;
    int r29;
    unsigned int r28;

    base = lbl_804F6810[arg0];
    OSDisableInterrupts();
    r29 = *(int *)(base + 0x8dc);
    r30 = *(int *)(base + 0x8bc);
    r28 = *(unsigned int *)(base + 0x8b8);
    OSRestoreInterrupts();
    if (r30 != -1) {
        if (r29 == 0) {
            r30 = -2;
        } else if (r28 != arg1) {
            if (fn_8021DC5C(base + 0x160, arg1, *(unsigned char *)(base + 0x98e), 0) == 0) {
                r30 = -2;
            } else {
                OSDisableInterrupts();
                *(unsigned int *)(base + 0x8b8) = arg1;
                OSRestoreInterrupts();
                r30 = 0;
            }
        } else {
            r30 = 0;
        }
    }
    return r30;
}
