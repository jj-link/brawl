#pragma force_active on
extern char *strstr(const char *, const char *);
extern unsigned long strlen(const char *);

int fn_80372F14(const char *a, const char *b, char *out, int size) {
    char c = *b;
    const char *p = strstr(a, b);
    char *o;
    int n;
    int i;
    char ch;
    unsigned long l;
    if (p == 0) return 0;
    l = strlen(b);
    o = out;
    n = size - 1;
    p += l;
    i = 0;
    for (; i < n && (ch = *p) != 0 && ch != c; i++, p++, o++) {
        *o = ch;
    }
    out[i] = 0;
    return 1;
}
