#pragma force_active on
int fn_803512B4(void *p);

int fn_803368A0(char *arg0, int arg1) {
    char *p;
    int count;
    int i;

    count = 0;
    if (arg0 == 0) {
        return 0;
    }
    p = arg0;
    for (i = 0; i < arg1; i++) {
        if (fn_803512B4(p) != 0) {
            count++;
        }
        p += 0xC;
    }
    return count;
}
