#pragma force_active on
extern "C" void* fn_115_BA24(void* pool, int index) {
    char* storage = static_cast<char*>(pool);
    if (index == 9) return storage + 0x11DA8;
    if (index == 8) return storage + 0xFDF0;
    if (index == 7) return storage + 0xDE38;
    if (index == 6) return storage + 0xBE80;
    if (index == 5) return storage + 0x9EC8;
    if (index == 4) return storage + 0x7F10;
    if (index == 3) return storage + 0x5F58;
    if (index == 2) return storage + 0x3FA0;
    if (index == 1) return storage + 0x1FE8;
    if (index == 0) return storage + 0x30;
    return 0;
}
