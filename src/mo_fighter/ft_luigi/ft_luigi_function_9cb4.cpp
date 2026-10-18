#include <types.h>
#pragma force_active on

// The fixed main-energy array contains one element after its 12-byte header.
extern "C" void* fn_99_9CB4(void* array, int index) {
    if (index == 0) {
        return static_cast<u8*>(array) + 0xC;
    }
    return 0;
}
