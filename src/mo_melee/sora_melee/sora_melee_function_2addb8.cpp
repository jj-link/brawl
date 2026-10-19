#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void*);

void* fn_27_2ADDB8(void* ptr, s32 size) {
    if (ptr != nullptr && size > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
}
