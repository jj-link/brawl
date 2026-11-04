#include <revolution/OS/OSError.h>
#pragma force_active on

extern int lbl_8059FE98;
extern int *lbl_805A1240;
extern const char lbl_80492F1C[];
extern const char lbl_80492EFC[];

extern int fn_803CB620(int, int, int, int, int, int, int, int, int, int *, int, int *);

int fn_803CC930(int *arg0, int arg1, int *arg2) {
    int result;
    int value;

    if (lbl_8059FE98 < 0) {
        result = 0xC1000000;
    } else if (arg1 == 0) {
        result = 0xC1000000;
    } else {
        if (arg2 != 0) {
            value = *arg2;
        } else {
            result = -4;
            goto done;
        }
        result = fn_803CB620(*arg0, 0x40, 0, 0, value, 0, 0, 0, 0, lbl_805A1240, arg1, arg2);
    }
done:
    if (result != 0) {
        OSReport(lbl_80492F1C, lbl_80492EFC, result);
    }
    return result;
}
