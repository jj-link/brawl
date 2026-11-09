#pragma force_active on
extern "C" int fn_80304A14(const float* a, const float* b) {
    int r = a[3] < b[3];
    return r | (((a[2] < b[2]) << 1) | (((a[0] < b[0]) << 3) | ((a[1] < b[1]) << 2)));
}
