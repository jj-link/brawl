#pragma force_active on
extern "C" void* fn_63_B0AC(char* base, int index) {
    int v = *(int*)(base + 8) >> 28;
    int i = v + index;
    i = (i >= 5) ? i - 5 : i;
    return base + i * 0x90 + 0xC;
}
