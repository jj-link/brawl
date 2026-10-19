#pragma force_active on
extern "C" void* fn_101_F064(void* object, int index) {
    char* bytes = static_cast<char*>(object);
    if (index == 1) return bytes + 0x10000 - 0x21DC;
    if (index == 0) return bytes + 0x10;
    return 0;
}
