#pragma force_active on
extern "C" void* fn_72_BFDC(unsigned char* base, int index) {
    int t = *(int*)(base + 8) >> 29;
    int i = t + index;
    if (i >= 3) {
        i -= 3;
    }
    return base + i * 0x90 + 0xc;
}
