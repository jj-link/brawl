#pragma force_active on
extern void OSReport(const char *, ...);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern char lbl_804927E0[];
extern int lbl_8059FE98;
extern int *lbl_805A1244;

int fn_803CB23C(int *arg0, int arg1, int *arg2, int arg3)
{
    char *base = lbl_804927E0;
    int result;

    if (lbl_8059FE98 < 0) {
        result = 0xC1000000;
    } else {
        lbl_805A1244[0] = arg1;
        lbl_805A1244[3] = arg3;
        if (arg2 != 0) {
            lbl_805A1244[4] = *arg2;
            result = fn_80212D40(*arg0, 1, lbl_805A1244, 0x18, 0, 0);
            if (result != 0) {
                OSReport(base + 0xD8);
                result = 0xC1000000;
            }
        } else {
            OSReport(base + 0xF4);
            result = 0xC1000000;
        }
    }
    if (result != 0) {
        OSReport(base + 0xAC, base + 0xC4, result);
    }
    return result;
}