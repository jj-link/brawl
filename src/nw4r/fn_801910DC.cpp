#pragma force_active on
extern "C" void fn_801910DC(int** arg, int val) {
    int* p = *arg;
    if (p != 0) {
        p[1] = val;
    }
}
