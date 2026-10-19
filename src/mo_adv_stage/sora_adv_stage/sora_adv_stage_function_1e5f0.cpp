#pragma force_active on
extern "C" {
void* fn_40_1E5F0(char* p, int idx) {
    int n = (((int*)p)[2] >> 26) + idx;
    if (n >= 24) {
        n -= 24;
    }
    return p + n * 0x68 + 0xc;
}
}
