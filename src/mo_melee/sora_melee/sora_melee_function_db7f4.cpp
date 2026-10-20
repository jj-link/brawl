#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_84458(void* p, int n);
void __dl__FPv(void*);

extern "C" void* fn_27_DB7F4(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xC, fn_27_84458, 0xC, 0x25);
        if (n > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
