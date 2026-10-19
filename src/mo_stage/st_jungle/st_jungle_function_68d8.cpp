#pragma force_active on
extern "C" void* fn_51_68D8(char* base, int index) {
    int tag = *(int*)(base + 8) >> 28;
    int sum = tag + index;
    int off = sum;
    if (off >= 6) {
        off = off - 6;
    }
    return base + (off * 8) + 12;
}
