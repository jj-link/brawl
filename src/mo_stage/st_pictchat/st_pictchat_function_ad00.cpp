#pragma force_active on
extern "C" unsigned char* fn_73_AD00(unsigned char* base, int index) {
    int shift = *(int*)(base + 8) >> 28;
    int sum = shift + index;
    if (sum >= 6) {
        sum -= 6;
    }
    return base + sum * 0x90 + 0xC;
}
