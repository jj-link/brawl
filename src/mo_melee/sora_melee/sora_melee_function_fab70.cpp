#pragma force_active on
extern "C" void* fn_27_FAB70(char* p, int idx) {
    int s = *(int*)(p + 0x18) >> 28;
    int i = s + idx;
    if (i >= 4) {
        i -= 4;
    }
    return p + i * 12 + 0x1c;
}
