#pragma force_active on
extern "C" void* fn_27_1AF7EC(char* base, int idx) {
    int off = *(int*)(base + 8) >> 22;
    int sum = off + idx;
    if (sum >= 0x127) {
        sum -= 0x127;
    }
    return base + sum * 4 + 0xc;
}
