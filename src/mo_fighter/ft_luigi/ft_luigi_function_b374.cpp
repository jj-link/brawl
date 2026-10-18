#include <types.h>
#pragma force_active on

// Returns array + 0xC when index is 0, otherwise null.
extern "C" void* fn_99_B374(void* array, int index) {
    if (index == 0) {
        return static_cast<u8*>(array) + 0xC;
    }
    return 0;
}
