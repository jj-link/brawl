#pragma force_active on
extern "C" char* fn_48_BEEC(char* base, int index) {
    int i = (*(int*)(base + 8) >> 26) + index;
    if (i >= 0x13) {
        i -= 0x13;
    }
    return base + i * 0x78 + 0xc;
}
