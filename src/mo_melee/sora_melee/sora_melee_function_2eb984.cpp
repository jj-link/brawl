#pragma force_active on
extern "C" void *fn_27_2EB984(int *self, int idx) {
    int r = (self[2] >> 29) + idx;
    if (r >= 3) {
        r -= 3;
    }
    return (char *)self + r * 12 + 12;
}
