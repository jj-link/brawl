#pragma force_active on
extern "C" void* fn_121_CCFC(void* pool, int index) {
    char* storage = static_cast<char*>(pool);
    if (index == 3) return storage + 0x5fac;
    if (index == 2) return storage + 0x3fd0;
    if (index == 1) return storage + 0x1ff4;
    if (index == 0) return storage + 0x18;
    return 0;
}
