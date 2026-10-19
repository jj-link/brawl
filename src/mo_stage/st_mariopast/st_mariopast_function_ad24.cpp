#include <stddef.h>
#pragma force_active on

extern "C" {
void __dt__19soCollisionHitGroupFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_48_AD24(void* ptr, int count) {
    if (ptr != NULL) {
        __destroy_arr((char*)ptr + 0xC, __dt__19soCollisionHitGroupFv, 0x38, 0xCD);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
