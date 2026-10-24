#pragma force_active on

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int status);
extern int lbl_80474E98[];

int fn_801E6AE8(int arg0, int arg1) {
    int temp;
    int status;

    temp = arg0 << 16;
    temp |= arg1 << 8;
    status = OSDisableInterrupts();
    temp = (lbl_80474E98[1] & 0xFC0000FF) | temp;
    lbl_80474E98[1] = temp;
    *(int *)0xCD006430 = temp;
    OSRestoreInterrupts(status);
    return temp;
}
