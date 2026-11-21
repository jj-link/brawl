#include <types.h>
#include <revolution/EXI/EXIHardware.h>
#pragma force_active on

extern int fn_8025FCD0();

int fn_80260074(u32 command, s8 *out, int size)
{
    int failed = 0;
    int result = 0;
    u32 word = 0;
    u32 cmd = command;

    EXI_CHAN_PARAMS[2].cpr = (EXI_CHAN_PARAMS[2].cpr & 0x405) | 0xC0;
    failed |= fn_8025FCD0(&cmd, 4, 1) == 0;
    while (EXI_CHAN_PARAMS[2].cr & 1) {}
    failed |= fn_8025FCD0(&word, 4, 0) == 0;
    while (EXI_CHAN_PARAMS[2].cr & 1) {}
    EXI_CHAN_PARAMS[2].cpr = EXI_CHAN_PARAMS[2].cpr & 0x405;

    switch (size) {
    case 1:
        *out = word >> 24;
        break;
    case 2:
        *(u16 *)out = (word >> 24) | ((word >> 8) & 0xFF00);
        break;
    default:
        *(u32 *)out = ((word << 24) | ((word << 8) & 0xFF0000)) |
                      ((word >> 24) | ((word >> 8) & 0x0000FF00));
        break;
    }
    return failed == 0;
}
