#pragma force_active on
extern "C" void* fn_71_F7CC(char* base, int index) {
    int sign = ((int*)base)[2] >> 28;
    int i = sign + index;
    if (i >= 7) {
        i -= 7;
    }
    return base + (i << 3) + 0xc;
}
