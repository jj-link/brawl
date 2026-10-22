#pragma force_active on
#pragma optimization_level 1
extern "C" {
extern unsigned char lbl_8040AA48[0x10];
extern unsigned char lbl_8040AA58[0x10];
extern unsigned char lbl_8040AA68[0x10];
int fn_8019D78C(void*, unsigned int* p) {
    if (*p == (unsigned int)lbl_8040AA58) return 1;
    unsigned int v = *p;
    if (v == (unsigned int)lbl_8040AA48) return 1;
    return (unsigned int)__cntlzw((unsigned int)lbl_8040AA68 - v) >> 5;
}
}
