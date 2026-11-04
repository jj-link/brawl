#pragma force_active on
void fn_803DAAE8(char *arg0, int arg1) {
    unsigned int r6;
    char *r7;
    char *p;

    r6 = *(unsigned int *)(arg0 + 0x1c);
    if (r6 == 0) {
        p = *(char **)(arg0 + 8);
        *(unsigned int *)(p + 0x1c) = 0;
        p = *(char **)(arg0 + 8);
        *(unsigned int *)(p + 0x18) = 0;
        return;
    }
    if (arg0 == 0) {
        r7 = 0;
    } else {
        r7 = *(char **)(*(char **)(arg0 + 8) + 0x268);
    }
    if (!(r6 & (*(unsigned short *)r7 - 1))) {
        r6 = *(unsigned int *)(arg0 + 0x24);
        if (!(r6 & (*(unsigned char *)(r7 + 6) - 1))) {
            if (r6 == 0) {
                return;
            }
            *(unsigned int *)(*(char **)(arg0 + 8) + 0x18) = (r6 - 1) >> *(unsigned char *)(r7 + 0x21);
            *(int *)(*(char **)(arg0 + 8) + 0x1c) = (int)(((unsigned int)(arg1 - 1) - *(unsigned int *)(r7 + 0x30)) >> *(unsigned char *)(r7 + 0x21)) + 2;
            return;
        }
    }
    *(unsigned int *)(*(char **)(arg0 + 8) + 0x18) = *(unsigned int *)(arg0 + 0x24) >> *(unsigned char *)(r7 + 0x21);
    *(int *)(*(char **)(arg0 + 8) + 0x1c) = (int)(((unsigned int)arg1 - *(unsigned int *)(r7 + 0x30)) >> *(unsigned char *)(r7 + 0x21)) + 2;
}
