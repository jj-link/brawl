#pragma force_active on
int fn_80370758(void **arg0, int arg1, int *arg2);

int fn_80368538(void **arg0, int arg1, int *arg2) {
    int sp8;
    int *temp_r3;
    void *temp_r6;

    if (arg0 == 0 || (temp_r6 = *arg0) == 0) {
        return 2;
    }
    if (*(int *)((char *)temp_r6 + 0x108) != 0) {
        *arg2 = 0;
        return 0;
    }
    if (fn_80370758(arg0, arg1, &sp8) != 0 && (temp_r3 = *(int **)((char *)sp8 + 8)) != 0) {
        *arg2 = *temp_r3;
    } else {
        *arg2 = -1;
    }
    return 0;
}
