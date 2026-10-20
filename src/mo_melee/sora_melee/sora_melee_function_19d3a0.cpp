#include <types.h>
#pragma force_active on

extern "C" {

void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__21soCollisionAttackPartFv(void*, int);
void __dl__FPv(void*);

void* fn_27_19D3A0(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 0x8);
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}

}
