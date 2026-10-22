#pragma force_active on
extern char lbl_80474DA8[];
int fn_8020B604(void*, void*);
int fn_8020A920(void*);
int fn_8020A784(void*, int, int);

int fn_801E3494(void) {
    unsigned char buf[8];
    int r = fn_8020B604(lbl_80474DA8, buf);
    if (r == 0 && buf[7] == 0x3f) {
        return 1;
    }
    if (r == 0 && buf[7] != 0x3f) {
        if (fn_8020A920(lbl_80474DA8) != 0) {
            return 0;
        }
    } else if (r != -12) {
        return 0;
    }
    if (fn_8020A784(lbl_80474DA8, 0x3f, 0) != 0) {
        return 0;
    }
    return 1;
}
