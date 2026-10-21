#pragma force_active on
#pragma optimization_level 1

extern "C" {
extern unsigned char lbl_8040A970[0x18];
extern unsigned char lbl_8040AA78[0x10];
extern unsigned char lbl_8040AA68[0x10];

bool fn_80199228(void* unused, unsigned int* p) {
    if (*p == (unsigned int)lbl_8040A970) {
        return true;
    }

    unsigned int type = *p;
    if (type == (unsigned int)lbl_8040AA78) {
        return true;
    }
    return type == (unsigned int)lbl_8040AA68;
}
}
