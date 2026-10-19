#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void*);

void* fn_27_2ADDF8(void* ptr, s32 n) {
    if (ptr != nullptr && n > 0)
        __dl__FPv(ptr);
    return ptr;
}
}
