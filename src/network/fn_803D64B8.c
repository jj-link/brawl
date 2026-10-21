#pragma force_active on
int fn_803D64B8(unsigned char *s1, unsigned char *s2, int n) {
    int i;
    unsigned char c;

    for (i = n; i != 0; i--) {
        c = *s1;
        if (c == 0 || *s2 == 0 || c != *s2) {
            return c - *s2;
        }
        s1++;
        s2++;
    }
    return 0;
}
