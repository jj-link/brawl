// Runtime.PPCEABI.H/fn_803FA558.c
char* strchr(const char* str, int chr) {
    const unsigned char* p = (const unsigned char*)str - 1;
    unsigned int target = chr & 0xFF;
    unsigned int c;

    while ((c = *++p) != 0) {
        if (c == target) {
            return (char*)p;
        }
    }
    if (target == 0) {
        return (char*)p;
    }
    return 0;
}
