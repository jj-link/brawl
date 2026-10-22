#pragma force_active on
extern int fn_8020B0E4(void *);
extern int fn_803C3CB8(int);
extern int fn_803C3F48(const char *);
extern char lbl_8059FCC8[4];

int fn_80398DB0(unsigned char *arg0, int *arg1) {
    int r;
    int ret;
    if (*(unsigned int *)(arg0 + 0x4) & 0x100) {
        r = fn_803C3CB8(*(int *)(arg0 + 0x98));
        if (r < 0) {
            if (r == 5) {
                r = fn_803C3F48(lbl_8059FCC8);
                switch (r) {
                case -5:
                case -15:
                    return -0x2E;
                case -4:
                    return -0x26;
                default:
                    return -0x15;
                }
            } else {
                return -0x15;
            }
        } else {
            *arg1 = r;
            return 0;
        }
    } else {
        r = fn_8020B0E4(arg0 + 0xC);
        ret = 0;
        if (r != 0) {
            ret = -0x15;
        }
        return ret;
    }
}
