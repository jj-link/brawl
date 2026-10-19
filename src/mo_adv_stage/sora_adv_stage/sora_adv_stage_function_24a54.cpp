#pragma force_active on
extern "C" {
void* fn_40_24A54(int* p, int idx) {
    int s = p[2] >> 30;
    int n = s + idx;
    if (n >= 1) {
        n -= 1;
    }
    return (char*)p + n * 0x38 + 0xc;
}
}
