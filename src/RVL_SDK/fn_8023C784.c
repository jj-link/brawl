#pragma force_active on
extern unsigned char lbl_80529CF8[];
extern char lbl_804810BC[];
extern void fn_802319E4(unsigned int, const char *);
extern unsigned char fn_80245468(unsigned char *);

int fn_8023C784(void) {
    unsigned char *p = lbl_80529CF8;
    if (p[0x27C0] >= 3U) {
        fn_802319E4(0xD0002, lbl_804810BC);
    }
    if (p[0x16AE] & 1) {
        if (fn_80245468(p + 0x16A8)) {
            return 1;
        }
        return 3;
    }
    return 6;
}