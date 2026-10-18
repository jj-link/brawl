#pragma force_active on
// Returns object + 0xC when flag is zero; otherwise returns null.
extern "C" void* fn_101_10958(void* object, int flag) {
    if (flag == 0) {
        return static_cast<char*>(object) + 0xC;
    }
    return 0;
}
