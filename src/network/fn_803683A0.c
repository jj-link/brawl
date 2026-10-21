#pragma force_active on
int fn_803683A0(void **arg0, int *arg1) {
    char *temp;

    if (arg0 == 0 || (temp = (char *)*arg0) == 0) {
        return 2;
    }
    if (*(int *)(temp + 0x108) != 0) {
        *arg1 = 0;
        return 0;
    }
    *arg1 = *(int *)(temp + 0x44C);
    return 0;
}
