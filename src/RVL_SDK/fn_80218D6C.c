#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern int lbl_804F6810[];

unsigned char fn_80218D6C(int arg0) {
    unsigned char *p;
    int s;
    unsigned char v;
    p = (unsigned char *)lbl_804F6810[arg0];
    s = OSDisableInterrupts();
    v = p[0x983];
    OSRestoreInterrupts(s);
    return v;
}
