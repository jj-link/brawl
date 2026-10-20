#include <types.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__25soCollisionAttackAbsoluteFv(void);
}

extern "C" void* fn_27_1A1114(void* p, s32 del) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))__dt__25soCollisionAttackAbsoluteFv, 0x68, 10);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
