#include <types.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_84198(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_DBB3C(void* p, s32 flags) {
    if (p) {
        __destroy_arr((char*)p + 0xC, fn_27_84198, 0xC, 4);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
