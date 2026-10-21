#pragma force_active on
extern "C" int fn_80307608(float* arg0, void* unused, int* arg1) {
    int r4;
    int r6;

    if (arg0[0] > arg0[1]) {
        r4 = 0;
        r6 = 0x80;
    } else {
        r4 = 1;
        r6 = 0x40;
    }

    if (arg0[2] > arg0[r4]) {
        r4 = 2;
        r6 = 0x20;
    }

    *arg1 = r4;
    return r6;
}
