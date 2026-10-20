#include <stddef.h>
#pragma force_active on

extern "C" void* fn_113_2A6C(void* ptr, short count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_113_2A10(void* ptr, short flags)
{
    if (ptr != NULL) {
        fn_113_2A6C(ptr, 0);
        if (flags > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
