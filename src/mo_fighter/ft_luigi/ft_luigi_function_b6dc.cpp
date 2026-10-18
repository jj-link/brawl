#include <types.h>
#pragma force_active on

extern "C" void* fn_99_B6DC(void* array, int index) {
    if (index == 0) {
        return static_cast<u8*>(array) + 0xC;
    }
    return 0;
}
