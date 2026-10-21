#pragma force_active on
extern unsigned int lbl_8059BEC8;
extern unsigned char gTRKCPUState[];

unsigned int fn_8040593C(unsigned int addr) {
    if (addr >= lbl_8059BEC8 && addr < lbl_8059BEC8 + 0x4000) {
        if (*(unsigned int *)(gTRKCPUState + 0x238) & 3) {
            return addr;
        }
    }
    if (addr >= 0x7e000000) {
        if (addr <= 0x80000000) {
            return addr;
        }
    }
    return (addr & 0x3fffffff) | 0x80000000;
}
