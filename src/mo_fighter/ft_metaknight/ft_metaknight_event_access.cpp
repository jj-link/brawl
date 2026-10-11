#include <types.h>

extern "C" void* fn_111_C2FC(void* object, s32 index) {
    if (index == 0) {
        return static_cast<u8*>(object) + 0xC;
    }
    return 0;
}
