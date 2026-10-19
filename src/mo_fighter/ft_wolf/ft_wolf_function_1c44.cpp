#include <types.h>
#pragma force_active on

extern "C" {
void fn_125_1B84(void* p, s16 flag);
void __dl__FPv(void* p);

void* fn_125_1C44(void* p, s16 flag) {
    if (p != 0) {
        fn_125_1B84(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
