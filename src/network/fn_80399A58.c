#pragma force_active on
extern void fn_801D5300(void *);
extern void fn_801D8690(const char *, int, const char *, ...);
extern char lbl_80491B7C[];
extern char lbl_80491B8C[];
extern int lbl_8059FCD0;

int fn_80399A58(void) {
    unsigned char buf[4];
    fn_801D5300(buf);
    if (buf[1] == 0 && ((buf[2] == 7 && buf[3] == 0) || buf[2] < 7U)) {
        fn_801D8690(lbl_80491B7C, 0x2B7, lbl_80491B8C);
    }
    return lbl_8059FCD0;
}