#pragma force_active on
extern "C" unsigned int fn_41_159D4(int x);

extern "C" void* fn_41_15FD4(char* p, int idx) {
    if (fn_41_159D4(idx) == 1) {
        return p + 0x2C;
    }
    return p + idx * 0xE0 + 0x2C;
}
