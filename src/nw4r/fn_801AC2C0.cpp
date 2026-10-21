#pragma force_active on
#pragma optimization_level 1

extern "C" {
extern unsigned char lbl_8040AA68[0x10];
extern unsigned char lbl_8040AB80[0x10];

int fn_801AC2C0(void* unused, unsigned int* p) {
    if (*p == (unsigned int)lbl_8040AB80) {
        return 1;
    }
    return *p == (unsigned int)lbl_8040AA68;
}
}
