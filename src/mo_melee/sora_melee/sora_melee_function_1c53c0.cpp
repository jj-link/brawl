#pragma force_active on
extern "C" void* fn_27_1C53C0(char* p, int n) {
    int t = *(int*)(p + 0x18) >> 28;
    int i = t + n;
    if (i >= 4) {
        i -= 4;
    }
    return p + 0x1c + i * 12;
}
