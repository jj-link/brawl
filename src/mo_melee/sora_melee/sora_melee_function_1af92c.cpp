#pragma force_active on
extern "C" void* fn_27_1AF92C(void* p, int idx) {
    int v = *(int*)((char*)p + 8) >> 22;
    int s = v + idx;
    if (s >= 0x11c) {
        s -= 0x11c;
    }
    return (char*)p + s * 4 + 0xc;
}
