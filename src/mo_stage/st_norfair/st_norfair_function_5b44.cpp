#include <stddef.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__21soCollisionAttackPartFv(void*, int);
void __dl__FPv(void*);
void* fn_54_5B44(void* self, int flags);
}

void* fn_54_5B44(void* self, int flags)
{
    if (self != NULL) {
        __destroy_arr((char*)self + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
