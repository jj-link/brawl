#pragma force_active on

extern unsigned int OSDisableInterrupts(void);
extern unsigned int OSRestoreInterrupts(unsigned int status);
extern unsigned char lbl_804FC1C0[64];

int fn_8022E1E4(unsigned int arg0) {
    unsigned int enabled = OSDisableInterrupts();
    int var_r31;
    if (arg0 < 0x10) {
        var_r31 = *(int *)(lbl_804FC1C0 + ((arg0 * 4) & 0x3FC));
    } else {
        var_r31 = 0;
    }
    OSRestoreInterrupts(enabled);
    return var_r31;
}
