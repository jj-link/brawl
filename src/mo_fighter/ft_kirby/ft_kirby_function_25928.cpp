#include <stddef.h>
#pragma force_active on

extern "C" {
void fn_96_25984(void* a, short b);
void __dl__FPv(void*);
}

extern "C" void* fn_96_25928(void* a, short b) {
    if (a != 0) {
        fn_96_25984(a, -1);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}
