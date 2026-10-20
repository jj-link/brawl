#pragma force_active on
extern "C" void* fn_27_FAB48(char* self, int idx) {
    int s = *(int*)(self + 0x18) >> 28;
    int i = s + idx;
    if (i >= 4) {
        i -= 4;
    }
    return self + i * 12 + 0x1c;
}
