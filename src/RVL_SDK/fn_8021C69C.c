#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern int fn_8021C564(int);
extern int lbl_804F6810[];

int fn_8021C69C(int arg0) {
    char *p;
    int level;
    int a;
    int b;

    p = (char *)lbl_804F6810[arg0];
    level = OSDisableInterrupts();
    a = *(int *)(p + 0x8BC);
    b = *(int *)(p + 0x8DC);
    OSRestoreInterrupts(level);
    if (a == -1 || b == 0 || fn_8021C564(arg0) != 0) {
        return 0;
    }
    return 1;
}
