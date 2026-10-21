#pragma force_active on
extern int lbl_805A0CC0;
extern int lbl_805A0CC4;
extern int lbl_805A0CC8;

extern unsigned int fn_801D536C(void);
extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int);
extern int fn_801E5DBC(int, int, unsigned int, void*, int);

int fn_802284C4(void)
{
    int enabled;
    unsigned char command;

    if (lbl_805A0CC0 != 0) {
        return 1;
    }

    if ((fn_801D536C() & 0x10000000) == 0) {
        lbl_805A0CC4 = 2;
        return 0;
    }

    enabled = OSDisableInterrupts();
    command = 0xF2;
    if (fn_801E5DBC(0, 1, 0xB0000000, &command, 1) == 0) {
        lbl_805A0CC4 = 5;
        OSRestoreInterrupts(enabled);
        return 0;
    }

    command = 0xF3;
    if (fn_801E5DBC(0, 1, 0xB0000000, &command, 1) == 0) {
        lbl_805A0CC4 = 5;
        OSRestoreInterrupts(enabled);
        return 0;
    }

    OSRestoreInterrupts(enabled);
    lbl_805A0CC0 = 1;
    lbl_805A0CC4 = 0;
    lbl_805A0CC8 = 0;
    return 1;
}
