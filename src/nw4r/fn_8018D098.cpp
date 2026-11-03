#pragma force_active on

extern "C" int fn_8018CD84(const int* a, int* b);

extern "C" int fn_8018D098(const int* arg0, const int* arg1) {
    int sp8;
    if (*arg0 != 0) {
        int tmp = *arg1;
        if (tmp != 0) {
            sp8 = tmp;
            int r = fn_8018CD84(arg0, &sp8);
            if (r != 0) {
                return (r - (*arg0 + 0x18)) / 16;
            }
        }
    }
    return -1;
}
