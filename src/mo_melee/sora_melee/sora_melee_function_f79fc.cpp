#pragma force_active on
extern "C" {
char* fn_27_F79FC(char* p, int idx) {
    int t = *(int*)(p + 0x18) >> 25;
    int n = t + idx;
    if (n >= 37) {
        n -= 37;
    }
    return p + n * 12 + 0x1c;
}
}
