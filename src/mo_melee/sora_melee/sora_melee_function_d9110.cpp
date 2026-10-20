#pragma force_active on
extern "C" void* fn_27_D9110(char* p, int idx) {
    int v = *(int*)(p + 8);
    int n = (v >> 26) + idx;
    if (n >= 0x10) {
        n -= 0x10;
    }
    return p + n * 0x14 + 0xc;
}
