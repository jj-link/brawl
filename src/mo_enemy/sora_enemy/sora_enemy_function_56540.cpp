#pragma force_active on
extern "C" void* fn_41_56540(void* obj, int idx) {
    if (idx == 4) {
        return (char*)obj + 0xcc;
    }
    if (idx == 3) {
        return (char*)obj + 0xa0;
    }
    if (idx == 2) {
        return (char*)obj + 0x74;
    }
    if (idx == 1) {
        return (char*)obj + 0x48;
    }
    if (idx == 0) {
        return (char*)obj + 0x1c;
    }
    return 0;
}
