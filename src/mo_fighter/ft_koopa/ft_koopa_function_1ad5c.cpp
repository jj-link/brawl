#include <stddef.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void* p);
void* fn_102_1AD5C(void* p, short flag);
}

extern "C" void* fn_102_1AD5C(void* p, short flag) {
    if (p != NULL && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
