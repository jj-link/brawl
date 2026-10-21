#pragma force_active on
int fn_80397640(char *arg0) {
    int n = 0;
    char *p = arg0;
    while (*p != 0) {
        n++;
        p++;
    }
    return n;
}
