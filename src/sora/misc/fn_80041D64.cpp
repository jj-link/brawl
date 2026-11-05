#pragma force_active on
extern "C" int fn_80041D64(float* a, float* b) {
    if (a[2] < b[0]) {
        return 0;
    }
    if (a[3] < b[1]) {
        return 0;
    }
    if (a[0] > b[2]) {
        return 0;
    }
    return (a[1] > b[3]) == 0;
}
