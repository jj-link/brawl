#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_48568(void* ptr, s32 size) {
    void* result = ptr;
    if (ptr != 0) {
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return result;
}
