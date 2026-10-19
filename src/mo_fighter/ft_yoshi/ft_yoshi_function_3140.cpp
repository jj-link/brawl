#include <stddef.h>
#pragma force_active on

extern "C" void* fn_27_14FCF4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_3140(void* ptr, short flags) {
    if (ptr != NULL) {
        fn_27_14FCF4(ptr, static_cast<short>(-1));
        if (flags > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
