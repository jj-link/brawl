#pragma force_active on
extern int fn_803AB8C4(void);

int fn_803AE438(int unused, int *arg1) {
    int temp_r3;

    if (arg1 == 0) {
        return 1;
    }
    *arg1 = 0;
    temp_r3 = fn_803AB8C4();
    return temp_r3 & ((-temp_r3 | temp_r3) >> 31);
}
