#pragma force_active on
extern "C" void* fn_92_AC20(void* pool, int index) {
    char* storage = static_cast<char*>(pool);
    if (index == 3) return storage + 0x5f88;
    if (index == 2) return storage + 0x3fb8;
    if (index == 1) return storage + 0x1fe8;
    if (index == 0) return storage + 0x18;
    return 0;
}
