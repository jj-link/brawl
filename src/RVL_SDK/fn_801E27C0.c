#pragma force_active on
extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int);
extern int fn_80212C08(int, int, void *, int, void *, int, int (*)(void), void *);
extern int fn_801E2970(void);
extern int lbl_805A070C;
extern int lbl_805A0710;
extern int lbl_805A071C;
extern unsigned int lbl_804DDFE0[8];
extern unsigned char lbl_804DE000[32];

int fn_801E27C0(unsigned int arg0, unsigned int arg1, unsigned int arg2)
{
    int enabled;
    int result;
    if (lbl_805A070C == 0) {
        return -10;
    }
    enabled = OSDisableInterrupts();
    if (lbl_805A071C != 0) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    lbl_805A071C = 1;
    OSRestoreInterrupts(enabled);
    lbl_804DDFE0[0] = (arg1 << 3) | arg2 | (arg0 << 7);
    lbl_804DDFE0[1] = 0;
    lbl_804DDFE0[2] = 0;
    lbl_804DDFE0[3] = 0;
    lbl_804DDFE0[4] = 0;
    lbl_804DDFE0[5] = -1;
    lbl_804DDFE0[6] = 0xFFFF0000;
    lbl_804DDFE0[7] = 0;
    result = fn_80212C08(lbl_805A0710, 0x5001, lbl_804DDFE0, 32,
                         lbl_804DE000, 32, fn_801E2970, 0);
    switch (result) {
    case 0:
        result = 1;
        break;
    }
    return result;
}
