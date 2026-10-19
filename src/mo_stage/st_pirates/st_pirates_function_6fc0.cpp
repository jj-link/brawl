#include <stddef.h>
#pragma force_active on

extern "C" void* fn_52_6F80(void* p, int n);

extern "C" void __destroy_arr(void* ptr, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_52_6FC0(void* this_, int flag) {
    void* r30 = this_;
    if (this_ != NULL) {
        __destroy_arr((void*)((char*)this_ + 0xC), (void (*)(void*, int))fn_52_6F80, 8UL, 7UL);
        if (flag > 0) {
            __dl__FPv(r30);
        }
    }
    return r30;
}
