#pragma force_active on
extern "C" void* fn_48_BE24(char* p, int idx) {
    int i = (*(int*)(p + 8) >> 26) + idx;
    if (i >= 0x13) {
        i -= 0x13;
    }
    return p + i * 0x38 + 0xC;
}
