#pragma force_active on
extern "C" int fn_80190C60(int* const* arg0, int arg1) {
    int* r5 = *arg0;
    if (r5 && arg1 >= 0 && arg1 <= 7) {
        return ((1 << arg1) & *r5) != 0;
    }
    return 0;
}
