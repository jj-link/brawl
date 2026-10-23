#pragma force_active on
extern "C" void fn_800A8B98(char* base, int index) {
    char* p = base + index * 16;
    p[0x78] &= ~0x80;
}
