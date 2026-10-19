#pragma force_active on
extern "C" void* fn_41_5C0FC(char* p, int n) {
    if (n == 4) {
        return p + 0xCC;
    }
    if (n == 3) {
        return p + 0xA0;
    }
    if (n == 2) {
        return p + 0x74;
    }
    if (n == 1) {
        return p + 0x48;
    }
    if (n == 0) {
        return p + 0x1C;
    }
    return 0;
}
