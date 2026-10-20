#pragma force_active on
extern "C" void* fn_27_268A78(char* p, int idx) {
    int x = *(int*)(p + 8);
    int i = (x >> 27) + idx;
    if (i >= 8) {
        i -= 8;
    }
    return p + i * 0x18 + 0xc;
}
