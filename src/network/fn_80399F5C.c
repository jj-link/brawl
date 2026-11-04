#pragma force_active on
int fn_80399F5C(char *dest, const char *src, int size) {
    char *p;
    int i;
    if (dest == 0 || src == 0) return 0;
    p = dest;
    i = 0;
    while (i + 1 < size) {
        *p = *src;
        if (*src == 0) break;
        src++;
        i++;
        p++;
    }
    if (i + 1 >= size && size != 0) dest[i] = 0;
    return i;
}