#include <types.h>
#pragma force_active on

// Returns a sub-object pointer selected by index:
// index 1 -> object + 0x1F58, index 0 -> object + 0x10, otherwise null.
extern "C" void* fn_99_9CCC(void* object, int index) {
    if (index == 1) {
        return static_cast<u8*>(object) + 0x1F58;
    }
    if (index == 0) {
        return static_cast<u8*>(object) + 0x10;
    }
    return 0;
}
