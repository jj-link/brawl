#pragma force_active on

extern unsigned int fn_8020FF8C(void);
extern unsigned int lbl_8048E108[];

unsigned int fn_803564B0(void) {
    unsigned int x = fn_8020FF8C();
    if (x + 0x10000 == 0xFFFF) {
        return 0;
    }
    x >>= 24;
    if (x >= 0xB2) {
        return 0;
    }
    return lbl_8048E108[x];
}
