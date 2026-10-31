#include <revolution/OS/OSError.h>
#pragma force_active on

extern int lbl_8059FE98;
extern const char lbl_80492F1C[];
extern const char lbl_80492F30[];

extern int fn_803CB620(int, int, int, int, int, int, int, int, int, int*, int, int);

int fn_803CC9F4(int* arg0) {
    int buf[8] __attribute__((aligned(32)));
    int result;

    if (lbl_8059FE98 < 0) {
        result = 0xC1000000;
    } else {
        result = fn_803CB620(*arg0, 0x41, 0, 0, 0, 0, 0, 0, 0, buf, 0, 0);
    }

    if (result != 0) {
        OSReport(lbl_80492F1C, lbl_80492F30, result);
    }

    return result;
}
