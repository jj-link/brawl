#pragma force_active on
extern "C" void* fn_27_1BC970(void* self, int idx) {
    int v = ((int*)self)[6] >> 27;
    int n = v + idx;
    if (n >= 10) {
        n -= 10;
    }
    return (char*)self + n * 12 + 0x1c;
}
