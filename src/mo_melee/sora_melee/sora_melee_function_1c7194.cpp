#pragma force_active on
extern "C" void* fn_27_1C7194(char* self, int idx) {
    int v = *(int*)(self + 0x18);
    int r0 = v >> 28;
    int i = r0 + idx;
    if (i >= 5) {
        i -= 5;
    }
    return self + 0x1c + i * 12;
}
