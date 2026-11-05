#pragma force_active on
extern int fn_8039929C(void *);
extern int fn_803C3828(int);
extern int fn_803C3F48(const char *);
extern int fn_80398768(void *);
extern int lbl_805A115C;
extern char lbl_8059FCC8[4];

int fn_80398680(void *arg0) {
    unsigned int *p = (unsigned int *)arg0;
    int var_r31 = 0;
    int result;

    if (p[1] == 9 || p[1] == 0x109) {
        var_r31 = fn_8039929C(arg0);
        lbl_805A115C = 0;
    }

    if (p[1] & 0x100) {
        int r = fn_803C3828(p[38]);
        if (r != 0) {
            if (r == 5) {
                switch (fn_803C3F48(lbl_8059FCC8)) {
                case -5:
                case -15:
                    result = -0x2E;
                    break;
                case -4:
                    result = -0x26;
                    break;
                default:
                    result = -0x11;
                    break;
                }
            } else {
                result = -0x11;
            }
        } else {
            result = 0;
        }
    } else {
        result = fn_80398768(arg0);
    }

    if (var_r31 != 0) {
        result = var_r31;
    }
    return result;
}