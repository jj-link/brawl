#pragma force_active on
extern "C" {
char* fn_27_1B0674(char* p, int idx) {
    int a = ((int*)p)[2] >> 28;
    int b = a + idx;
    if (b < 6) {
    } else {
        b = b - 6;
    }
    return p + b * 0x34 + 0xC;
}
}
