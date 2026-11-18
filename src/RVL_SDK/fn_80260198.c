#include <revolution/EXI/EXIHardware.h>
#pragma force_active on
extern int fn_8025FCD0(int *, int, int);
int fn_80260198(int command, void *src, int length)
{
    int data;
    int failed = 0;
    unsigned int control;
    switch (length) {
    case 1:
        data = *(unsigned char *)src << 24;
        break;
    case 2: {
        unsigned int v = *(unsigned short *)src;
        data = (v << 24) | ((v << 8) & 0x00FF0000);
        break;
    }
    default: {
        unsigned int v = *(unsigned int *)src;
        data = ((v << 24) | ((v << 8) & 0x00FF0000)) |
               ((v >> 24) | ((v >> 8) & 0x0000FF00));
        break;
    }
    }
    EXI_CHAN_PARAMS[2].cpr = (EXI_CHAN_PARAMS[2].cpr & 0x405) | 0xC0;
    failed |= fn_8025FCD0(&command, 4, 1) == 0;
    while (EXI_CHAN_PARAMS[2].cr & 1) {}
    failed |= fn_8025FCD0(&data, 4, 1) == 0;
    while (EXI_CHAN_PARAMS[2].cr & 1) {}
    control = EXI_CHAN_PARAMS[2].cpr;
    EXI_CHAN_PARAMS[2].cpr = control & 0x405;
    return failed == 0;
}
