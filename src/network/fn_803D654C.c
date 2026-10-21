#pragma force_active on
int fn_803D654C(unsigned short *arg0, unsigned short *arg1, int arg2) {
    int i;
    for (i = arg2; i; i--) {
        if (*arg0 == 0 || *arg1 == 0 || *arg0 != *arg1)
            return *arg0 - *arg1;
        arg0++;
        arg1++;
    }
    return 0;
}
