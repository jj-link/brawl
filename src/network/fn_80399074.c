#pragma force_active on
extern int fn_803C3FD0(void);
extern int fn_803C3F44(void);
extern int fn_803C3F48(const char *);
extern char lbl_8059FCC8[4];

int fn_80399074(void *unused, int *arg1) {
    int temp_r3;

    temp_r3 = fn_803C3FD0();
    *arg1 = temp_r3;
    if (temp_r3 < 0) {
        if (fn_803C3F44() == 5) {
            switch (fn_803C3F48(lbl_8059FCC8)) {
            case -5:
            case -15:
                return -0x2E;
            case -4:
                return -0x26;
            default:
                return -0x2B;
            }
        } else {
            return -0x2B;
        }
    } else {
        return 0;
    }
}
