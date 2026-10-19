#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1400D4(void* ptr, s32 val) {
    if (ptr && val > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
