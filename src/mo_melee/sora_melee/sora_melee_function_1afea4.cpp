#pragma force_active on
extern "C" void* fn_27_1AFEA4(void* self, int idx) {
    int n = (((int*)self)[2] >> 22) + idx;
    if (n >= 0x11b) {
        n -= 0x11b;
    }
    return (char*)self + n * 4 + 0xc;
}
