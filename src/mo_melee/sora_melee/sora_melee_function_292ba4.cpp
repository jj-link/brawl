#pragma force_active on
extern "C" char* fn_27_292BA4(char* p, int i) {
    int s = *(int*)(p + 0x18) >> 29;
    int n = s + i;
    if (n >= 2) {
        n -= 2;
    }
    return p + n * 12 + 0x1c;
}
