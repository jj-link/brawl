#pragma force_active on
extern "C" void* fn_110_BFBC(void* object, int flag) {
    if (flag == 0) {
        return static_cast<char*>(object) + 0x0c;
    }
    return 0;
}
