#pragma force_active on

extern "C" void fn_80190CA4(int **arg0, int arg1) {
    int *temp_r5 = *arg0;
    if (temp_r5 != 0 && arg1 >= 0 && arg1 <= 7) {
        *temp_r5 |= 1 << arg1;
    }
}
