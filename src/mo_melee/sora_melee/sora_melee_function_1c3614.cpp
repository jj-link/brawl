#pragma force_active on
extern "C" void* fn_27_1C3614(void* p, int idx) {
    unsigned char* base = (unsigned char*)p;
    int n = (*(int*)(base + 0x18) >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return base + 0x1c + n * 12;
}
