#pragma force_active on
extern "C" void* fn_100_C598(void* object, int flag) {
    if (flag == 0) {
        return static_cast<char*>(object) + 0xC;
    }
    return 0;
}
