#pragma force_active on
extern "C" void* fn_27_1B037C(void* p, int n) {
    int idx = (*(int*)((char*)p + 8) >> 27) + n;
    if (idx >= 13) {
        idx -= 13;
    }
    return (char*)p + idx * 0x60 + 0xc;
}
