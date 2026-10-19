#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_9FA50(void* ptr, int count) {
    if (ptr != nullptr) {
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
