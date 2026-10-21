#pragma force_active on
#pragma optimization_level 1

extern "C" {
extern unsigned char lbl_8040A9D0[0x10];
extern unsigned char lbl_8040AA68[0x10];
extern unsigned char lbl_8040AA78[0x10];

int fn_8019B87C(void* unused, unsigned int* p) {
    unsigned int v = *p;
    if (v == (unsigned int)lbl_8040A9D0) {
        return 1;
    }
    v = *p;
    if (v == (unsigned int)lbl_8040AA78) {
        return 1;
    }
    return (unsigned int)((unsigned int)lbl_8040AA68 - v) == 0;
}
}
