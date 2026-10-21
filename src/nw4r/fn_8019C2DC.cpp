#pragma force_active on
#pragma optimization_level 1
extern "C" {
extern unsigned char lbl_8040AA20[0x10];
extern unsigned char lbl_8040AA78[0x10];
extern unsigned char lbl_8040AA68[0x10];

int fn_8019C2DC(void* unused, unsigned int* p) {
    if (*p == (unsigned int)lbl_8040AA20) {
        return 1;
    }
    unsigned int val = *p;
    if (val == (unsigned int)lbl_8040AA78) {
        return 1;
    }
    unsigned int diff = (unsigned int)lbl_8040AA68 - val;
    unsigned int x = __cntlzw(diff);
    return x >> 5;
}
}
