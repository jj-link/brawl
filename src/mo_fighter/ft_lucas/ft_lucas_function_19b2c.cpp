#include <types.h>
#pragma force_active on

extern "C" void* fn_114_19B2C(void* object, int index) {
    if (index == 5) {
        return static_cast<char*>(object) + 0x10000 - 0x6260;
    }
    if (index == 4) {
        return static_cast<char*>(object) + 0x7e20;
    }
    if (index == 3) {
        return static_cast<char*>(object) + 0x5ea0;
    }
    if (index == 2) {
        return static_cast<char*>(object) + 0x3f20;
    }
    if (index == 1) {
        return static_cast<char*>(object) + 0x1fa0;
    }
    if (index == 0) {
        return static_cast<char*>(object) + 0x20;
    }
    return 0;
}
