#include <types.h>
#pragma force_active on

extern "C" void* fn_110_C52C(void* object, int index) {
    if (index == 0) {
        return static_cast<char*>(object) + 0x0c;
    }
    return 0;
}
