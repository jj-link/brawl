#include <types.h>
#pragma force_active on

extern "C" {
void fn_8006CE1C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_8006E7F0(void*, int);
}

extern "C" void* fn_8006CE5C(void* p, int flag) {
    if (p != 0) {
        __destroy_arr((char*)p + 0x90, fn_8006CE1C, 0x10, 8);
        __destroy_arr((char*)p + 0xC, fn_8006CE1C, 0x10, 8);
        fn_8006E7F0(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
