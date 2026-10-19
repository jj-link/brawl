#pragma force_active on
extern "C" void* fn_95_D0AC(char* pool, int index) {
    if (index == 3) return pool + 0x5db4;
    if (index == 2) return pool + 0x3e80;
    if (index == 1) return pool + 0x1f4c;
    if (index == 0) return pool + 0x18;
    return 0;
}
