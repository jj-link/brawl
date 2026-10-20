#pragma force_active on
extern "C" void fn_27_1D5474(char* base, unsigned int idx, int off) {
    char* p = *(char**)(base + (idx << 2) + 0x184);
    p[off] = 0;
}
