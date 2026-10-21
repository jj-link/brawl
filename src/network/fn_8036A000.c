#pragma force_active on

int fn_8036A000(int unused, int *arg1, int arg2) {
    arg1 = *(int **)((char *)arg1 + 8);
    if (arg1 != 0) {
        int v = *arg1;
        if (v > arg2) {
            *arg1 = v - 1;
        }
    }
    return 1;
}
