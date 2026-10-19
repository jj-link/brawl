#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_27_300624(void* ptr, s32 size) {
    if (ptr != nullptr && size > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
