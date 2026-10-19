#pragma force_active on
extern "C" void* fn_47_4C04(char* base, int index) {
    int offset = *(int*)(base + 0x8) >> 30;
    int i = offset + index;
    if (i >= 1) {
        i -= 1;
    }
    return base + i * 0xa0 + 0xc;
}
