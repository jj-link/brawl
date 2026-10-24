#pragma force_active on
extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int);

extern int lbl_805A07B4;
extern unsigned int lbl_805A0810;
extern int lbl_805A0838;

int fn_801E9F60(int arg0)
{
    unsigned int state;
    int old;
    int enabled;

    old = lbl_805A0838;
    lbl_805A0838 = arg0;

    enabled = OSDisableInterrupts();
    state = lbl_805A0810;

    switch (state) {
    case 0:
    case 3:
    case 6:
    case 7:
        state = 0;
        break;
    case 1:
    case 4:
        state = 1;
        break;
    case 2:
    case 5:
        break;
    }

    OSRestoreInterrupts(enabled);

    switch (state) {
    case 1:
        switch (lbl_805A0838) {
        case 1:
            lbl_805A07B4 = 0x7530;
            break;
        case 2:
            lbl_805A07B4 = 0xAFC8;
            break;
        default:
            lbl_805A07B4 = 0x3A98;
            break;
        }
        break;
    default:
        switch (lbl_805A0838) {
        case 1:
            lbl_805A07B4 = 0x8CA0;
            break;
        case 2:
            lbl_805A07B4 = 0xD2F0;
            break;
        default:
            lbl_805A07B4 = 0x4650;
            break;
        }
        break;
    }

    return old;
}
