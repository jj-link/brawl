#include <revolution/EXI/EXIHardware.h>
#pragma force_active on
extern int fn_8025FCD0(int *, int, int);
int fn_8026029C(int command, int *data, int length)
{
    int word;
    int failed;
    int *p = data;
    int n = length;
    unsigned int control;
    EXI_CHAN_PARAMS[2].cpr = (EXI_CHAN_PARAMS[2].cpr & 0x405) | 0xC0;
    failed = fn_8025FCD0(&command, 4, 1) == 0;
    while (EXI_CHAN_PARAMS[2].cr & 1) {}
    while (n > 0) {
        failed |= fn_8025FCD0(&word, 4, 0) == 0;
        while (EXI_CHAN_PARAMS[2].cr & 1) {}
        *p++ = word;
        n -= 4;
    }
    control = EXI_CHAN_PARAMS[2].cpr;
    EXI_CHAN_PARAMS[2].cpr = control & 0x405;
    return failed == 0;
}
