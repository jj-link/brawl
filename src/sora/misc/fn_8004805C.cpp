#pragma force_active on
#pragma optimization_level 1

extern "C" {
extern unsigned char lbl_8040ABD8[0x10];
extern unsigned char lbl_8040ABC0[0x18];
extern unsigned char lbl_8040AB90[0x10];
extern unsigned char lbl_8040AB80[0x10];
extern unsigned char lbl_8040AA68[0x10];

int fn_8004805C(void* unused, unsigned int* p) {
    if (*p == (unsigned int)lbl_8040ABD8) return 1;
    unsigned int v = *p;
    if (v == (unsigned int)lbl_8040ABC0) return 1;
    if (v == (unsigned int)lbl_8040AB90) return 1;
    if (v == (unsigned int)lbl_8040AB80) return 1;
    return (unsigned int)__cntlzw((unsigned int)lbl_8040AA68 - v) >> 5;
}
}
