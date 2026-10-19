#pragma force_active on
extern "C" int fn_57_371C(unsigned char *obj, int unused, int *out1, int *out2) {
    if (obj[0x1d8] >= 4) {
        *out1 = 6;
        *out2 = 3;
        return 1;
    }
    return 0;
}
