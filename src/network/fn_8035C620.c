#pragma force_active on
extern int fn_803A7994(int a, int* b);

int fn_8035C620(int arg) {
    int local;
    int result = fn_803A7994(arg, &local);
    if (result == 0) {
        return -1;
    }
    return local;
}
