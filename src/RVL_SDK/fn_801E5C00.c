#pragma force_active on
extern int fn_801E56DC(int, unsigned int, unsigned int *);
extern int fn_801E5A88(int, unsigned int, unsigned int *);
extern int lbl_805A0770, lbl_805A0774, lbl_805A0778, lbl_805A077C;

void fn_801E5C00(int chan, unsigned int dev) {
    unsigned int id;
    if (fn_801E56DC(chan, dev, &id)) {
        switch ((int)id) {
        case -1:
        case (int)0x80000004:
        case (int)0x80000008:
        case (int)0x80000010:
        case (int)0x80000020:
        case 4:
        case 8:
        case 0x10:
        case 0x20:
        case 0x01010000:
        case 0x01020000:
        case 0x02020000:
        case 0x03010000:
        case 0x04020100:
        case 0x04020200:
        case 0x04020300:
        case 0x04040404:
        case 0x04060000:
        case 0x04120000:
        case 0x04130000:
        case 0x04220000:
            break;
        default:
            if (fn_801E5A88(chan, dev, &id)) {
                lbl_805A077C = chan;
                lbl_805A0778 = dev;
                lbl_805A0774 = 0xA5FF005A;
                lbl_805A0770 = 0xA5FF005A;
            }
            break;
        }
    }
}