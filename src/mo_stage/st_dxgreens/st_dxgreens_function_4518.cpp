#include <stddef.h>
#pragma force_active on

extern "C" {
void __dt__18soCollisionHitPartFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_79_4518(void* array, int param) {
    if (array != NULL) {
        __destroy_arr((char*)array + 0xc, __dt__18soCollisionHitPartFv, 0x68, 0x1e);
        if (param > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
}
