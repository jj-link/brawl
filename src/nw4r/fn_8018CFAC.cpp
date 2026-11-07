#pragma force_active on
extern "C" int fn_8018CD84(const int*, int*);
extern "C" int fn_8018CFAC(const int* arg0, const int* arg1) {
    int sp8;
    if (*arg0 != 0) {
        int tmp = *arg1;
        if (tmp != 0) {
            sp8 = tmp;
            int r = fn_8018CD84(arg0, &sp8);
            if (r != 0) {
                return *arg0 + *(int*)(r + 0xC);
            }
        }
    }
    return 0;
}
