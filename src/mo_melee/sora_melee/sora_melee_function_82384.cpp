#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void*);

void* fn_27_82384(void* ptr, s32 size) {
    if (ptr && size > 0)
        __dl__FPv(ptr);
    return ptr;
}
}
