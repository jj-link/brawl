#pragma force_active on
extern "C" void* fn_118_B628(char* object, int index) {
    if (index == 2) {
        return object + 0x40bc;
    }
    if (index == 1) {
        return object + 0x2068;
    }
    if (index == 0) {
        return object + 0x14;
    }
    return 0;
}
