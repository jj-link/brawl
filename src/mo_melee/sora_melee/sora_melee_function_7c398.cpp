#include <types.h>
#pragma force_active on

extern "C" {
extern void __dl__FPv(void*);

void* fn_27_7C398(void* ptr, s32 count) {
    if (ptr != nullptr && count > 0)
        __dl__FPv(ptr);
    return ptr;
}
}
