#include <types.h>
#pragma force_active on

extern "C" void* fn_27_169898(void* ptr, int count) {
    if (ptr && count > 0)
        operator delete(ptr);
    return ptr;
}
