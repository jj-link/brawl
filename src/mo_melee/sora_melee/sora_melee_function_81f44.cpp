#include <types.h>
#pragma force_active on

extern "C" {
extern void __dl__FPv(void*);

void* fn_27_81F44(void* ptr, s32 count) {
    if (ptr && count > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
}
