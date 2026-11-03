#include <revolution/OS/OSError.h>
#pragma force_active on

extern int fn_802123A8(void *, int);
extern char lbl_804927E0[];
extern char lbl_80563960[];
extern int lbl_8059FE98;

int fn_803CC014(unsigned int arg0, int **arg1)
{
    char *base = lbl_804927E0;
    int value;
    int result = 0;

    if (lbl_8059FE98 < 0) {
        result = 0xC1000000;
        goto done;
    }
    if (arg0 >= 4U) {
        OSReport(base + 0x498);
        return -4;
    }
    {
        int *pointer = *arg1;
        int *nullPointer[1] = {0};
        if (pointer == nullPointer[0]) {
            OSReport(base + 0x4BC);
            return -4;
        }
    }
    value = fn_802123A8(lbl_80563960 + arg0 * 32, 0);
    if (value < 0) {
        if (value == -2) {
            OSReport(base + 0x2DC, lbl_80563960 + (arg0 << 5));
        } else if (value == -6) {
            OSReport(base + 0x2F0, lbl_80563960 + (arg0 << 5));
        } else {
            OSReport(base + 0x304, lbl_80563960 + (arg0 << 5), value);
        }
    }
    (*arg1)[0] = value;
    if ((*arg1)[0] < 0) {
        result = -1;
        OSReport(base + 0x4E0);
    }
    (*arg1)[9] = 0;
    (*arg1)[6] = 0x4000;
    (*arg1)[8] = 0;
done:
    return result;
}
