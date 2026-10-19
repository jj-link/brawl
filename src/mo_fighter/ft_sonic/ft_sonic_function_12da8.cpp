#include <types.h>
#pragma force_active on

extern "C" void* fn_123_12E04(void* ptr, short count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_123_12DA8(void* ptr, short flag) {
    if (ptr != nullptr) {
        fn_123_12E04(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
