#pragma force_active on
extern "C" {
void* fn_27_1B0DFC(void* p, int idx) {
    int r0 = ((int*)p)[2] >> 29;
    int i = r0 + idx;
    if (i >= 3) {
        i -= 3;
    }
    return (char*)p + i * 0x78 + 0xC;
}
}
