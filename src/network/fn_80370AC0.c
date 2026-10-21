#pragma force_active on
int fn_80370AC0(void *p0, int *p1, int *p2) {
    int *temp_r6;

    temp_r6 = (int *)p1[2];
    if (temp_r6 != 0 && p2[0] == temp_r6[0]) {
        p2[1] = (int)p1;
        return 0;
    }
    return 1;
}
