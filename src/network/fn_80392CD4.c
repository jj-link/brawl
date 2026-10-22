#pragma force_active on
static int lower(signed char c) { return ((c >= 'A') & (c <= 'Z')) ? c + 32 : c; }
int fn_80392CD4(signed char *a, signed char *b) {
    signed char ch;
    int x1, x2;
    while (x2 = lower(*b), ch = *a, x1 = lower(ch), x1 == x2) {
        if (ch == 0 || ch == ' ') return 0;
        a++;
        b++;
    }
    return -1;
}
