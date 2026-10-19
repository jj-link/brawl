#pragma force_active on
typedef int s32;

extern "C" void* fn_41_5DFD0(char* p, s32 k) {
    if (k == 4) {
        return p + 0xcc;
    }
    if (k == 3) {
        return p + 0xa0;
    }
    if (k == 2) {
        return p + 0x74;
    }
    if (k == 1) {
        return p + 0x48;
    }
    if (k == 0) {
        return p + 0x1c;
    }
    return 0;
}
