#pragma force_active on
extern int lbl_804F6810[];
extern unsigned int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(unsigned int);

int fn_8021AE80(int arg0) {
    int *p;
    unsigned int level;
    int r;

    p = (int *)lbl_804F6810[arg0];
    level = OSDisableInterrupts();
    r = *(int *)((char *)p + 0x83C);
    OSRestoreInterrupts(level);
    return r;
}
