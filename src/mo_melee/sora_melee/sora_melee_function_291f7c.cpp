#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" {
void* fn_27_291F7C(void* p, long n);
}

void* fn_27_291F7C(void* p, long n) {
    if (p != nullptr && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
