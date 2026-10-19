#pragma force_active on
// Select one of six embedded controllers. Unknown indices return null.
extern "C" void* fn_101_19FC4(void* object, int index) {
    char* bytes = static_cast<char*>(object);
    if (index == 5) {
        char* p = bytes + 0x10000;
        return p - 0x6260;
    }
    if (index == 4) return bytes + 0x7E20;
    if (index == 3) return bytes + 0x5EA0;
    if (index == 2) return bytes + 0x3F20;
    if (index == 1) return bytes + 0x1FA0;
    if (index == 0) return bytes + 0x20;
    return 0;
}
