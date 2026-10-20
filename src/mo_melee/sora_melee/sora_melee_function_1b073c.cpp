#pragma force_active on
extern "C" void* fn_27_1B073C(void* p, int idx) {
    int r0 = *(int*)((char*)p + 8) >> 28;
    int n = r0 + idx;
    if (n >= 7) {
        n -= 7;
    }
    return (char*)p + n * 0x18 + 0xc;
}
