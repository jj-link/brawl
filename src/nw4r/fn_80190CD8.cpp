#pragma force_active on
extern "C" void fn_80190CD8(int **arg0, int arg1) {
    int *p = *arg0;
    if (p == 0) return;
    if (arg1 < 0) return;
    if (arg1 > 7) return;
    *p &= ~(1 << arg1);
}
