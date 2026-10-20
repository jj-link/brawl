#pragma force_active on
extern "C" void* fn_27_1CF200(char* p, int idx) {
    int a = *(int*)(p + 0x18) >> 26;
    int i = a + idx;
    if (i >= 16) {
        i -= 16;
    }
    return p + i * 12 + 0x1c;
}
