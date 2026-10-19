#pragma force_active on
extern "C" char* fn_40_24B1C(char* self, int idx) {
    int cnt = *(int*)(self + 8);
    int n = (cnt >> 30) + idx;
    if (n >= 1) {
        n -= 1;
    }
    return self + n * 0x78 + 0xc;
}
