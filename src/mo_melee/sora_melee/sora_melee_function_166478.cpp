#include <types.h>
#pragma force_active on

extern "C" {

extern void __dl__FPv(void*);

void* fn_27_166478(void* ptr, s32 count) {
    if (ptr && count > 0)
        __dl__FPv(ptr);
    return ptr;
}

}
