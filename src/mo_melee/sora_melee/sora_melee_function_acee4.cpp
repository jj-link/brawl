#include <types.h>
#pragma force_active on

extern "C" void* fn_27_ACEE4(void* ptr, s32 size) {
    if (ptr != nullptr && size > 0) {
        operator delete(ptr);
    }
    return ptr;
}
