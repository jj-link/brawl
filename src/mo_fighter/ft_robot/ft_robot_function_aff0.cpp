#pragma force_active on
extern "C" void* fn_120_AFF0(char* self, int mode) {
    if (mode == 1) return self + 0x2034;
    if (mode == 0) return self + 0x10;
    return 0;
}
