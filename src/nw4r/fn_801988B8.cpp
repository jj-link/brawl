#pragma force_active on
#pragma optimization_level 1

extern "C" {
extern unsigned char lbl_8040A940[0x18];
extern unsigned char lbl_8040AA68[0x10];
extern unsigned char lbl_8040AA78[0x10];

bool fn_801988B8(void*, const unsigned int* p) {
    if (*p == (unsigned int)lbl_8040A940) {
        return true;
    }

    unsigned int value = *p;
    if (value == (unsigned int)lbl_8040AA78) {
        return true;
    }

    return value == (unsigned int)lbl_8040AA68;
}
}
