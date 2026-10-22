#pragma force_active on
extern void OSReport(const char *, ...);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern char lbl_804927E0[];
extern int lbl_8059FE98;
extern int *lbl_805A1238;
extern int *lbl_805A1244;

int fn_803CB148(int *arg0, int arg1, int *arg2, int arg3)
{
    char *base = lbl_804927E0;
    int result;

    if (lbl_8059FE98 < 0) {
        result = 0xC1000000;
    } else {
        lbl_805A1244[0] = arg1;
        lbl_805A1244[3] = arg3;
        lbl_805A1244[4] = 0;

        if (arg2 != 0) {
            result = fn_80212D40(*arg0, 2, lbl_805A1244, 0x18,
                                 lbl_805A1238, 4);
            if (result != 0) {
                OSReport(base + 0x74);
                result = 0xC1000000;
            } else {
                *arg2 = *lbl_805A1238;
            }
        } else {
            OSReport(base + 0x90);
            result = 0xC1000000;
        }
    }

    if (result != 0) {
        OSReport(base + 0xAC, base + 0x60, result);
    }

    return result;
}
