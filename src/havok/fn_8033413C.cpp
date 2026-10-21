#pragma force_active on
extern "C" int fn_8033413C(const int* arg0) {
    int count = 0;
    while (*arg0 != 0) {
        count++;
        arg0++;
    }
    return count;
}
