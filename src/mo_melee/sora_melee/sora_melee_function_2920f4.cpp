#include <types.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_84458(void* p, int n);

void* fn_27_2920F4(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_84458, 0xC, 0x1E);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
