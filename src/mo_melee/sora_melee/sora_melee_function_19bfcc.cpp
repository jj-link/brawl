#include <types.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_85800(void);
}

extern "C" void* fn_27_19BFCC(void* p, int del) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_85800, 0x14, 2);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
