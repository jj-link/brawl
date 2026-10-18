#include <types.h>
#pragma force_active on

// Returns the element at offset 0xC when index is 0, otherwise null.
extern "C" void* fn_99_B7C4(void* array, int index) {
    if (index == 0) {
        return static_cast<u8*>(array) + 0xC;
    }
    return 0;
}
