#pragma force_active on
extern "C" void* fn_27_1B005C(char* p, int idx) {
    int r4 = (*(int*)(p + 8) >> 27) + idx;
    if (r4 >= 10) {
        r4 -= 10;
    }
    return p + r4 * 0x68 + 0xc;
}
