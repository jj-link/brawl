#pragma force_active on
extern "C" void* fn_47_5054(char* base, int index) {
    int field = *(int*)(base + 8);
    int n = (field >> 28) + index;
    if (n >= 6) {
        n -= 6;
    }
    return base + (n << 3) + 12;
}
