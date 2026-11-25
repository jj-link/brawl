#pragma force_active on

extern unsigned int lbl_8059BEC8;
extern unsigned int lbl_804947D0[];
extern unsigned char gTRKCPUState[];
extern unsigned char gTRKInterruptVectorTable[];

extern void fn_8000449C(void *, const void *, unsigned int);
extern void TRK_flush_cache(void *, unsigned int);

void fn_80405810(void)
{
    unsigned int *p;
    unsigned int addr;
    unsigned int dest;
    int i;
    unsigned int mask;

    if (0x44U >= lbl_8059BEC8 &&
        0x44U < lbl_8059BEC8 + 0x4000 &&
        (*(unsigned int *)(gTRKCPUState + 0x238) & 3)) {
        p = (unsigned int *)0x44;
    } else {
        p = (unsigned int *)0x80000044;
    }

    mask = *p;
    p = lbl_804947D0;
    i = 0;
    do {
        if ((mask & (1 << i)) && i != 4) {
            addr = *p;
            if (addr >= lbl_8059BEC8 &&
                addr < lbl_8059BEC8 + 0x4000 &&
                (*(unsigned int *)(gTRKCPUState + 0x238) & 3)) {
                dest = addr;
            } else if (addr >= 0x7e000000 && addr <= 0x80000000) {
                dest = addr;
            } else {
                dest = (addr & 0x3fffffff) | 0x80000000;
            }

            fn_8000449C((void *)dest, gTRKInterruptVectorTable + addr, 0x100);
            TRK_flush_cache((void *)dest, 0x100);
        }
        i++;
        p++;
    } while (i <= 14);
}
