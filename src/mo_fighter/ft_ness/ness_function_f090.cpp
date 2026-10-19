#pragma force_active on
// Return a fixed sub-object for index 1 or 0; unknown indices return null.
extern "C" void* fn_101_F090(void* object, int index) {
    char* bytes = static_cast<char*>(object);
    if (index == 1) return bytes + 0x241C;
    if (index == 0) return bytes + 0x10;
    return 0;
}
