#pragma force_active on
extern "C" void* fn_27_1AF9A4(char* p, int idx) {
    int a = *(int*)(p + 8);
    int i = (a >> 22) + idx;
    if (i >= 0x118) {
        i -= 0x118;
    }
    return p + 12 + i * 4;
}
