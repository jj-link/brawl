#include <types.h>
#pragma force_active on

extern "C" {
extern void __dl__FPv(void*);

void* fn_27_318D44(void* array, s32 size) {
    if (array && size > 0)
        __dl__FPv(array);
    return array;
}
}
