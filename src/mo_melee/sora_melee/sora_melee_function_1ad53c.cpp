#pragma force_active on
extern "C" void* fn_27_1AD53C(char* p, int idx) {
    int s = *(int*)(p + 0x18) >> 27;
    int n = s + idx;
    if (n >= 12) {
        n -= 12;
    }
    return p + 0x1c + n * 12;
}
