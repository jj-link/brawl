#include <types.h>
#pragma force_active on

extern "C" void* fn_27_2B1B68(void* ptr, s32 count) {
    if (ptr != 0 && count > 0) {
        delete ptr;
    }
    return ptr;
}
