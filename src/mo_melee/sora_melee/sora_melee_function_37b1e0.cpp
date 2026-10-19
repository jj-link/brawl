#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_37B1E0(void* ptr, s32 count) {
    if (ptr && count > 0)
        __dl__FPv(ptr);
    return ptr;
}
