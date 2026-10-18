#pragma force_active on
extern "C" {
void fn_110_C79C(void *a0, int a1, int a2) {
    *(int *)a0 = a1;
    *(((int *)a0) + 1) = a2;
}
}
