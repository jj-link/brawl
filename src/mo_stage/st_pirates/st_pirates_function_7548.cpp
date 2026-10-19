#pragma force_active on
extern "C" char* fn_52_7548(char* self, int index) {
    int t = (((int*)self)[2] >> 30) + index;
    if (t >= 1) {
        t = t - 1;
    }
    return self + t * 0x78 + 0xc;
}
