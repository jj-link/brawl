#pragma force_active on
#pragma optimization_level 1

extern "C" {
extern unsigned char lbl_8040AA08[0x18];
extern unsigned char lbl_8040A9D0[0x10];
extern unsigned char lbl_8040AA78[0x10];
extern unsigned char lbl_8040AA68[0x10];

int fn_8019B814(void* unused, unsigned int* p) {
    if (*p == (unsigned int)lbl_8040AA08) return 1;
    unsigned int v = *p;
    if (v == (unsigned int)lbl_8040A9D0) return 1;
    if (v == (unsigned int)lbl_8040AA78) return 1;
    return (unsigned int)__cntlzw((unsigned int)lbl_8040AA68 - v) >> 5;
}
}
