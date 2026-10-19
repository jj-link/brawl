#pragma force_active on
extern "C" char* fn_48_BB34(char* p, int idx) {
    int n = (*(int*)(p + 8) >> 26) + idx;
    if (n >= 0x19) {
        n -= 0x19;
    }
    return p + n * 0x38 + 0xc;
}
