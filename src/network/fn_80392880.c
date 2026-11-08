#pragma force_active on
int fn_80392880(char *arg0, int arg1) {
    int width = 0;
    char *p = arg0 + 1;
    int c = *arg0;
    int i;
    for (i = 0; i < arg1; i++) {
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ') {
            width += 1;
        } else {
            width += 3;
        }
        c = *p;
        p += 1;
    }
    return width;
}