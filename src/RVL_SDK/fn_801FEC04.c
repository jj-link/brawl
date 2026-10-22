#pragma force_active on

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);

void fn_801FEC04(unsigned int arg0, unsigned int arg1)
{
    unsigned int t6;
    unsigned int t5;
    unsigned int t4;
    int interrupts = OSDisableInterrupts();

    t6 = *(unsigned short *)0xCC005030 & 0xFFFFE000;
    t5 = t6 | (arg0 >> 16);
    *(unsigned short *)0xCC005030 = t5;

    t5 = *(unsigned short *)0xCC005032 & 0xFFFF001F;
    t4 = t5 | (arg0 & 0xFFFF);
    *(unsigned short *)0xCC005032 = t4;

    t4 = *(unsigned short *)0xCC005036 & 0xFFFF8000;
    *(unsigned short *)0xCC005036 = t4 | ((arg1 >> 5) & 0xFFFF);

    OSRestoreInterrupts(interrupts);
}
