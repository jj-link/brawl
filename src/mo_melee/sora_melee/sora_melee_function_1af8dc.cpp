#pragma force_active on
extern "C" void* fn_27_1AF8DC(void* p, int idx) {
    int n = (((int*)p)[2] >> 22) + idx;
    if (n >= 0x11f) {
        n -= 0x11f;
    }
    return (char*)p + n * 4 + 0xc;
}
