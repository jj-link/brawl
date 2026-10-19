#pragma force_active on
extern "C" char* fn_68_D710(char* base, int index) {
    int n = (*(int*)(base + 8) >> 30) + index;
    if (n >= 1) {
        n = n - 1;
    }
    return base + n * 0x90 + 0xc;
}
