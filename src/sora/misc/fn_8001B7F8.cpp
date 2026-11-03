#pragma force_active on
extern "C" {
extern int strncmp(const char *s1, const char *s2, unsigned long n);
extern char lbl_8059C550[5];
extern char lbl_8059C558[5];
extern char lbl_8059C560[6];
extern char lbl_8059C568[4];
extern int lbl_8059C528;

int fn_8001B7F8(const char *arg0) {
    if (strncmp(arg0, lbl_8059C550, 4) == 0) {
        return 0;
    }
    if (strncmp(arg0, lbl_8059C558, 4) == 0) {
        return 1;
    }
    if (strncmp(arg0, lbl_8059C560, 5) == 0) {
        return 2;
    }
    if (strncmp(arg0, lbl_8059C568, 3) == 0) {
        return 3;
    }
    if (arg0[0] == 'v' && arg0[1] == 'f') {
        if (arg0[2] >= '0' && arg0[2] <= '9') {
            return 4;
        }
        return lbl_8059C528;
    }
    return lbl_8059C528;
}
}
