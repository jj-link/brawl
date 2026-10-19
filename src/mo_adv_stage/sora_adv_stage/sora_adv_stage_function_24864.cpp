#include <types.h>

#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__18soCollisionHitPartFv(void*, int);
void __dl__FPv(void*);

void* fn_40_24864(void* ptr, int flag) {
    if (ptr) {
        __destroy_arr(reinterpret_cast<u8*>(ptr) + 0xc, __dt__18soCollisionHitPartFv, 0x68, 1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
