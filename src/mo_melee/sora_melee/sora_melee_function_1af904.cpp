#pragma force_active on
extern "C" void* fn_27_1AF904(char* p, int idx) {
    int n = (*(int*)(p + 8) >> 22) + idx;
    if (n >= 0x11e) {
        n -= 0x11e;
    }
    return p + n * 4 + 0xc;
}
