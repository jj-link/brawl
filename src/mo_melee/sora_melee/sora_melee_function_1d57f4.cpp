#include <types.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_8D588(void*, int);

void* fn_27_1D57F4(void* object, int deleting) {
    if (object != 0) {
        __destroy_arr((char*)object + 0xc, (void (*)(void*, int))fn_27_8D588, 0xc, 0x9);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
