#pragma force_active on
int fn_803736BC(const unsigned char *a, const unsigned char *b) {
    int i;
    for (i = 0; i < 32; i++, b++, a++) {
        if (i != 0 && i != 13 && *a != *b)
            return 0;
    }
    return 1;
}