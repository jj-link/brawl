#pragma force_active on
extern "C" {
int fn_40_24AA8(int* p) {
    int x = p[2];
    int r = (x << 2) | ((unsigned)x >> 30);
    int m = r & 0xE0000000;
    return m >> 30;
}
}
