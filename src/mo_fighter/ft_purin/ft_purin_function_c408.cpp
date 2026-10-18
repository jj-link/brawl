#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void* p);

void* fn_124_C408(void* p, s16 n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
