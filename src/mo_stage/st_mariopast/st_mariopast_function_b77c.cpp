#pragma force_active on
extern "C" char* fn_48_B77C(int* base, int index) {
    int i = (base[2] >> 25) + index;
    if (i >= 0x3a) {
        i -= 0x3a;
    }
    return (char*)base + i * 0xa0 + 0xc;
}
