#pragma force_active on
// Return the embedded controller at offset 0xC when index is 0; otherwise null.
extern "C" void* fn_101_EF00(void* object, int index) {
    char* bytes = static_cast<char*>(object);
    if (index == 0) return bytes + 0xC;
    return 0;
}
