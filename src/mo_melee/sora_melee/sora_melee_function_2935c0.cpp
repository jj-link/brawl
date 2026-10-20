#pragma force_active on
extern "C" void* fn_27_2935C0(char* self, int idx) {
    int v = *(int*)(self + 0x18) >> 29;
    int i = v + idx;
    if (i >= 2) {
        i -= 2;
    }
    return self + i * 12 + 0x1c;
}
