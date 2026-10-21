#pragma force_active on
extern void OSReport(const char* fmt, ...);
extern int fn_80212588(int);
extern char lbl_804771F0[];
extern int lbl_8059EAF8;
extern char lbl_805A09C5;

int fn_801FC8E8(void) {
    if (fn_80212588(lbl_8059EAF8) != 0) {
        OSReport(lbl_804771F0);
        return 0;
    }
    lbl_805A09C5 = 0;
    return 1;
}
