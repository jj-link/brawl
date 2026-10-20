#pragma force_active on
extern "C" void* fn_27_1E7904(char* self, int idx) {
    int v = *(int*)(self + 0x18);
    int s = v >> 28;
    int i = s + idx;
    if (i >= 4) {
        i -= 4;
    }
    return self + 0x1c + i * 12;
}
