#pragma force_active on
extern "C" int fn_80190BF8(int* arg0, int arg1) {
    int val = *arg0;
    if (val != 0 && arg1 >= 0 && arg1 <= 7) {
        return val + (arg1 << 5) + 4;
    }
    return 0;
}
