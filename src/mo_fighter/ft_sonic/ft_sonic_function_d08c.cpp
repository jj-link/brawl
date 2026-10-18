#pragma force_active on
extern "C" void* fn_123_D08C(void* object, int index) {
    if (index == 0) {
        return static_cast<char*>(object) + 0x0c;
    }
    return 0;
}
