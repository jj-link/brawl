#pragma force_active on
extern "C" void* fn_27_1C0EAC(void* p, int idx) {
    unsigned char* base = (unsigned char*)p;
    int n = (((int*)p)[6] >> 27) + idx;
    if (n >= 10) {
        n -= 10;
    }
    return base + n * 12 + 0x1c;
}
