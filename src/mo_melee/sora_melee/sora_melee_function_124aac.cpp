#include <types.h>
#pragma force_active on

extern "C" void* fn_27_124990(void* p, int n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_124AAC(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_124990, 0x18, 0x10);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
