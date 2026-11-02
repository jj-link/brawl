#pragma force_active on
extern void OSReport(const char *, ...);
extern int fn_803CB620(int, unsigned int, int, int, int, void *, int, int, int, int *, int, int);
extern char lbl_804927E0[];

int fn_803CC7A8(int *arg0, int *arg1)
{
    char *base = lbl_804927E0;
    int buf[4];
    int result;

    result = 0xC1000000;
    if (arg1 != 0) {
        OSReport(base + 0x688);
        fn_803CB620(arg0[0], 0x10, 3, 1, 4, 0, 0, 0, 0, buf, 0, 0);

        result = fn_803CB620(arg0[0], 0x37, 3, 1, arg0[4], 0, 0, 0, 0, buf, 0, 0);
        if (result != 0) {
            OSReport(base + 0x6A0, result);
            return result;
        }

        result = fn_803CB620(arg0[0], 0x33, 3, 1, 0, arg1, 1, 4, 0, buf, 0, 0);
        if (result != 0) {
            OSReport(base + 0x6C0, result);
        } else {
            OSReport(base + 0x6E0, arg1[0], arg1[1]);
        }

        result = fn_803CB620(arg0[0], 0x10, 3, 1, 0x200, 0, 0, 0, 0, buf, 0, 0);
    }

    return result;
}
