#pragma force_active on
#pragma optimization_level 1

extern "C" {
extern unsigned char lbl_8040A9D0[0x10];
extern unsigned char lbl_8040AA78[0x10];
extern unsigned char lbl_8040AA68[0x10];

int fn_8019B94C(void* unused, unsigned int* p) {
    unsigned int base = (unsigned int)lbl_8040A9D0;
    if ((base, base + 0x24) == (unsigned int)*p) return 1;
    unsigned int v = (unsigned int)*p;
    if (v == base + 0x10) return 1;
    unsigned int z = base + 0x10;
    if (v == z - 0x10) return 1;
    if (v == (unsigned int)lbl_8040AA78) return 1;
    return (unsigned int)__cntlzw((unsigned int)lbl_8040AA68 - v) >> 5;
}
}
