// Runtime.PPCEABI.H/fn_803FA588.c
char* strrchr(const char* str, int chr) {
    const unsigned char* p = (const unsigned char*)str - 1;
    const unsigned char* result;
    unsigned int target = chr & 0xFF;
    unsigned int c;

    result = 0;
    while ((c = *++p) != 0) {
        if (c == target) {
            result = p;
        }
    }
    if (result != 0) {
        return (char*)result;
    }
    if (target != 0) {
        return 0;
    }
    return (char*)p;
}
