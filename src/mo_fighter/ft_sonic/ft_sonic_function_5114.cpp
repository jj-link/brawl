#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_5114(void* ptr, short count)
{
    if (ptr != NULL && count > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
