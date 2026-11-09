#pragma force_active on
int fn_803C27EC(char *p) {
    int mode;
    int i;
    if (p == 0) return 10;
    i = 1;
    switch (p[0]) {
    case 'r': mode = 2; break;
    case 'w': mode = 1; break;
    case 'a': mode = 4; break;
    default: return 0;
    }
    if (p[1] == 'b') i = 2;
    switch (p[i++]) {
    case 0: return mode;
    case 't':
    default: return 0;
    case '+':
        switch (p[i]) {
        case 0: return mode | 8;
        default: return 0;
        }
    }
}