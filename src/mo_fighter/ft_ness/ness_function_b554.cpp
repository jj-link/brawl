#pragma force_active on
extern "C" void* fn_101_B468();

extern "C" void* fn_101_B554(void* p, int kind) {
    switch (kind) {
    case 0:
        return p;
    case 1:
        return (char*)p + 0x490;
    case 2:
        return fn_101_B468();
    default:
        return fn_101_B468();
    }
}