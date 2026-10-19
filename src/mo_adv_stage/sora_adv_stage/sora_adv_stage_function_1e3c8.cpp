#pragma force_active on
extern "C" void* fn_40_1E3C8(void* self, int idx) {
    int v = *(int*)((char*)self + 8);
    v = v >> 26;
    int n = v + idx;
    if (n >= 24) {
        n -= 24;
    }
    return (char*)self + n * 0xa0 + 0xc;
}
