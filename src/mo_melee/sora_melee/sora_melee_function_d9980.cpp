#pragma force_active on
extern "C" {
void* fn_27_D9980(char* base, int idx) {
    int i = (*(int*)(base + 8) >> 28) + idx;
    if (i >= 5) {
        i -= 5;
    }
    return base + i * 0x78 + 0xc;
}
}
