#include <stddef.h>
#pragma force_active on

extern "C" {
void fn_27_3544C(void*, short);
void __dl__FPv(void*);

void* fn_123_4464(void* p, short flag) {
    if (p != NULL) {
        fn_27_3544C(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
