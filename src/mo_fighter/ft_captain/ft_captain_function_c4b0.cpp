#pragma force_active on
extern "C" void* fn_100_C4B0(void* self, int flag) {
    if (flag == 0) {
        return static_cast<char*>(self) + 0xC;
    }
    return 0;
}
