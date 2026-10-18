#include <types.h>
#pragma force_active on

extern "C" void* fn_99_B50C(void* object, int index) {
    if (index == 0) {
        return static_cast<u8*>(object) + 0xC;
    }
    return 0;
}
