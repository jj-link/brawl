#pragma force_active on
extern "C" char* fn_79_5AB4(char* self, int index) {
    int adj = *(int*)(self + 8) >> 30;
    int n = adj + index;
    if (n >= 1) {
        n -= 1;
    }
    return self + n * 0x78 + 0xc;
}
