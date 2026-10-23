#pragma force_active on
extern char *strcpy(char *, const char *);
extern char *strncpy(char *, const char *, unsigned int);
extern int strlen(const char *);
extern char lbl_8059EB4C[2];

void fn_8020CD14(char *dst, const char *src) {
    int i = strlen(src);
    const char *p = src + i;

    for (; i >= 0; i--, p--) {
        if (*p == '/') {
            break;
        }
    }

    if (i == 0) {
        strcpy(dst, lbl_8059EB4C);
        return;
    }

    strncpy(dst, src, i);
    dst[i] = 0;
}
