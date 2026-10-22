#pragma force_active on
extern int fn_803C3A48(void);
extern int fn_803C3F48(const char *);
extern char lbl_8059FCC8[4];

int fn_80398E6C(void) {
    int r = fn_803C3A48();
    if (r != 0) {
        if (r == 5) {
            switch (fn_803C3F48(lbl_8059FCC8)) {
            case -5:
            case -15:
                return -0x2E;
            case -4:
                return -0x26;
            default:
                return -0x15;
            }
        }
        return -0x15;
    }
    return 0;
}
