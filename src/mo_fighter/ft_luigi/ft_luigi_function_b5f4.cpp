#include <types.h>
#pragma force_active on

// Returns the first element's storage (offset 0xC) for index 0, otherwise null.
extern "C" void* fn_99_B5F4(void* array, int index) {
    if (index == 0) {
        return static_cast<u8*>(array) + 0xC;
    }
    return 0;
}
