#include <types.h>
#pragma force_active on

extern "C" void* fn_125_C8D8(void* object, int index) {
    if (index == 4) {
        return static_cast<char*>(object) + 0x860c;
    }
    if (index == 3) {
        return static_cast<char*>(object) + 0x6490;
    }
    if (index == 2) {
        return static_cast<char*>(object) + 0x4314;
    }
    if (index == 1) {
        return static_cast<char*>(object) + 0x2198;
    }
    if (index == 0) {
        return static_cast<char*>(object) + 0x1c;
    }
    return 0;
}
