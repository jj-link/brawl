typedef unsigned short u16;

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);
extern void fn_801DFB80(int, int);
extern char lbl_804DD500[];

#pragma force_active on
void fn_801E000C(int arg0, u16 arg1) {
    int level = OSDisableInterrupts();
    char *p = lbl_804DD500;
    char *q;
    if (*(int *)(p + 0x48) != 0) {
        OSRestoreInterrupts(level);
        q = 0;
    } else {
        *(int *)(p + 0x44) = level;
        q = p + 0x14;
        *(int *)(p + 0x48) = 1;
    }
    q = q + arg0 * 2;
    if (arg1 != *(u16 *)(q + 0x1c)) {
        *(u16 *)(q + 0x1c) = arg1;
        fn_801DFB80(1, 0x14);
        return;
    }
    fn_801DFB80(0, 0x14);
}
