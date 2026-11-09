#include <revolution/EXI/EXIHardware.h>
#pragma force_active on
extern void fn_801DD2A0(unsigned int);
extern int fn_8025FCD0(int *, int, int);
void fn_8025FFB8(void)
{
    int cmd1;
    int cmd2;
    fn_801DD2A0(0x18000);
    while ((EXI_CHAN_PARAMS[2].cr & 1) == 1) {}
    EXI_CHAN_PARAMS[2].cpr = 0;
    cmd1 = 0xB4000000;
    cmd2 = 0xD4000000;
    EXI_CHAN_PARAMS[2].cpr = (EXI_CHAN_PARAMS[2].cpr & 0x405) | 0xC0;
    fn_8025FCD0(&cmd1, 4, 1);
    while (EXI_CHAN_PARAMS[2].cr & 1) {}
    fn_8025FCD0(&cmd2, 4, 1);
    while (EXI_CHAN_PARAMS[2].cr & 1) {}
    EXI_CHAN_PARAMS[2].cpr = EXI_CHAN_PARAMS[2].cpr & 0x405;
}
