#include <types.h>
#pragma force_active on

extern "C" void* fn_102_A22C(void* object, int index) {
    if (index == 5) {
        return static_cast<char*>(object) + 0x9db4;
    }
    if (index == 4) {
        return static_cast<char*>(object) + 0x7e30;
    }
    if (index == 3) {
        return static_cast<char*>(object) + 0x5eac;
    }
    if (index == 2) {
        return static_cast<char*>(object) + 0x3f28;
    }
    if (index == 1) {
        return static_cast<char*>(object) + 0x1fa4;
    }
    if (index == 0) {
        return static_cast<char*>(object) + 0x20;
    }
    return 0;
}
