#pragma force_active on
extern "C" char* fn_62_60AC(char* self, int idx) {
    int sh = *(int*)(self + 8) >> 30;
    int t = sh + idx;
    if (t >= 1) {
        t = t - 1;
    }
    return self + t * 0x78 + 0xc;
}
