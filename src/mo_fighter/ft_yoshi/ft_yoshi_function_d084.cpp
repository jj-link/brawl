#pragma force_active on
extern "C" void* fn_95_D084(char* base, int mode) {
    if (mode == 1) {
        return base + 0x1fec;
    }
    if (mode == 0) {
        return base + 0x10;
    }
    return 0;
}
