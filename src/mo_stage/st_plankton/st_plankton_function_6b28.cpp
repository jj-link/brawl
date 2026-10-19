#pragma force_active on
extern "C" unsigned char* fn_74_6B28(unsigned char* base, int index) {
    int n = *(int*)(base + 8);
    int i = (n >> 30) + index;
    if (i >= 1) {
        i -= 1;
    }
    return base + i * 0x68 + 0xc;
}
